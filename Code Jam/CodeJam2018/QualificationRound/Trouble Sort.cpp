#include <bits/stdc++.h>
using namespace std;

void doTestCase() {
    int n;
    vector<int> a, b;

    cin >> n;
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        if (i & 1) {
            b.push_back(x);
        }
        else {
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int res = n + 1;
    for (int i = 0; i < a.size(); i++) {
        if (i < b.size() && a[i] > b[i]) {
            res = min(res, i * 2);
        }
    }
    for (int i = 0; i < b.size(); i++) {
        if (i + 1 < a.size() && b[i] > a[i + 1]) {
            res = min(res, i * 2 + 1);
        }
    }
    if (res == n + 1) {
        cout << "OK\n";
        return;
    }
    cout << res << "\n";
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        doTestCase();
    }

    return 0;
}