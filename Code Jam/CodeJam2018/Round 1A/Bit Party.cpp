#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 2e18;
const int MAX = 1010;

ll m[MAX], s[MAX], p[MAX];
ll r, b, c;

int canSolve(ll t) {
    vector<ll> a(c);
    for (int i = 0; i < c; i++) {
        a[i] = (t > p[i] ? min(m[i], (t - p[i]) / s[i]) : 0);
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll tot = 0;
    for (int i = 0; i < r && i < c; i++) {
        tot += a[i];
    }
    return tot >= b;
}

ll doTestCase() {
    cin >> r >> b >> c;
    for (int i = 0; i < c; i++) {
        cin >> m[i] >> s[i] >> p[i];
    }
    ll lo = 0, hi = INF;
    ll res = INF;
    while (lo <= hi) {
        ll mi = (lo + hi) / 2;
        if (canSolve(mi)) {
            res = mi;
            hi = mi - 1;
        }
        else {
            lo = mi + 1;
        }
    }
    return res;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": " << doTestCase() << "\n";
    }

    return 0;
}