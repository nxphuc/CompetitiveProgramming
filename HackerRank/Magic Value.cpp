#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5 + 10;
const int MOD = 1e9 + 7;

ll a[MAX];
int n;
ll s;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        ll v_max = 0, v_min = 1e18;
        ll gcd = a[i];
        ll m = 0;
        for (int j = i; j <= n; j++) {
            ++m;
            v_max = max(v_max, a[j] * m);
            if (a[j] == 0 || v_min == 0) {
                v_min = 0;
            }
            else {
                gcd = __gcd(gcd, a[j]);
                v_min = min(v_min, gcd);
            }
            s = (s + ((v_max - v_min) % MOD) * m) % MOD;
        }
    }
    cout << s << "\n";

    return 0;
}