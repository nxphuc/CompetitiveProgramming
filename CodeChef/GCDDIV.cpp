#include <bits/stdc++.h>
using namespace std;

string solve(int g, int k) {
    for (int i = 2; i*i <= g; i++) {
        if (i > k) {
            break;
        }
        while (g % i == 0) {
            g /= i;
        }
    }
    return (g <= k ? "YES\n" : "NO\n");
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t, n, k, g, x;

    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> g;
        for (int i = 1; i < n; i++) {
            cin >> x;
            g = __gcd(g, x);
        }
        cout << solve(g, k);
    }

    return 0;
}