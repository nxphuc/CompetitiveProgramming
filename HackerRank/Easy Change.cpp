#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t, c, p;
    cin >> t;
    while (t--) {
        cin >> c >> p;
        int res = 0;
        p -= c;
        if (p % 10) {
            res = 10 - p % 10;
            p += res;
        }
        if (p == 20 || p == 50 || p == 100 || p == 200 || p == 500 || p == 1000) {
            cout << res << "\n";
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}