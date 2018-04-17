#include <bits/stdc++.h>
using namespace std;

void doTestCase() {
    int n;
    int a[30];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (true) {
        int mx_pos = -1;
        int mx = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mx) {
                mx = a[i];
                mx_pos = i;
            }
            cnt += a[i] > 0;
        }
        if (mx == 0) {
            break;
        }
        if (cnt > 2) {
            cout << " " << char(mx_pos + 'A');
            a[mx_pos]--;
        }
        else {
            int other = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] && i != mx_pos) {
                    other = i;
                    break;
                }
            }
            if (a[other] == a[mx_pos]) {
                cout << " " << char(mx_pos + 'A') << char(other + 'A');
                a[mx_pos]--;
                a[other]--;
            }
            else {
                cout << " " << char(mx_pos + 'A');
                a[mx_pos]--;
            }
        }
    }
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ":";
        doTestCase();
        cout << "\n";
    }

    return 0;
}