#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

inline double calc(ll k, ll p, ll x, ll m) {
    return 1.0 * m *x + 1.0 * k *p / m;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    ll k, p, x;
    cin >> k >> p >> x;

    ll l = 1, r = INF / x;
    ll ml, mr;
    double result = 1.0 * INF * INF;
    while (1) {
        ml = (2LL * l + r) / 3;
        mr = (2LL * r + l) / 3;
        if (ml == l || mr == r || ml == mr) {
            break;
        }
        double fml = calc(k, p, x, ml);
        double fmr = calc(k, p, x, mr);
        if (fml > fmr) {
            l = ml;
        }
        else {
            r = mr;
        }
    }
    for (ll i = l; i <= r; i++) {
        result = min(result, calc(k, p, x, i));
    }
    cout << fixed << setprecision(3) << result;

    return 0;
}