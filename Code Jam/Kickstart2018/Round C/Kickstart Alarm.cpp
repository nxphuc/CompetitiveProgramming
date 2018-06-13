#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll sum_pow[MAX];
ll a[MAX];

ll fastPow(ll b, ll p) {
    if (!p) {
        return 1;
    }
    ll ret = fastPow(b, p / 2);
    ret = (ret * ret) % MOD;
    if (p & 1) {
        ret = (ret * b) % MOD;
    }
    return ret;
}

ll calcPow(ll r, ll n) {
    ll x = fastPow(r, n + 1);
    return (((x - r + MOD) % MOD) * fastPow(r - 1, MOD - 2)) % MOD;
}

inline ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

void doTestCase() {
    ll n, k, x_1, y_1, c, d, e_1, e_2, f;

    cin >> n >> k >> x_1 >> y_1 >> c >> d >> e_1 >> e_2 >> f;

    a[1] = (x_1 + y_1) % f;
    for (int x_new, y_new, i = 2; i <= n; i++) {
        x_new = (c * x_1 + d * y_1 + e_1) % f;
        y_new = (d * x_1 + c * y_1 + e_2) % f;
        x_1 = x_new;
        y_1 = y_new;
        a[i] = (x_1 + y_1) % f;
    }

    sum_pow[1] = k;
    for (int i = 2; i <= n; i++) {
        sum_pow[i] = (sum_pow[i - 1] + calcPow(i, k)) % MOD;
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + mult(a[i], sum_pow[i] + k * (n - i))) % MOD;
    }
    cout << res << "\n";
}

int main() {
    freopen("test.in", "rt", stdin);
    // freopen("test.ou", "wt", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        doTestCase();
    }

    return 0;
}