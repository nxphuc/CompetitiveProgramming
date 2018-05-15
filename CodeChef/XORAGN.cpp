#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t, n, x, res;
    cin >> t;
    while (t--) {
        cin >> n;
        res = 0;
        while (n--) {
            cin >> x;
            res ^= 2 * x;
        }
        cout << res << "\n";
    }

    return 0;
}