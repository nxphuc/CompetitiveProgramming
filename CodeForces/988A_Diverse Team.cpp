#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, k;
    vector<int> a, b;

    cin >> n >> k;
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    int m = 0;
    for (int i = 0; i < n && m < k; i++) {
        int flag = 1;
        for (int j = 0; j < m; j++) {
            if (a[b[j]] == a[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            b.push_back(i);
            m++;
        }
    }
    if (b.size() < k) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int i = 0; i < k; i++) {
            cout << b[i]+1 << " ";
        }
    }

    return 0;
}