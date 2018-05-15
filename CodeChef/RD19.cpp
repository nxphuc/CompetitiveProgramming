#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t, n, g, x;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> g;
        while (--n) {
            cin >> x;
            g = __gcd(x, g);
        }
        if (g == 1) {
            cout << "0\n";
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}