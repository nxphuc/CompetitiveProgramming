#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll n, ll m, ll k) {
    k++;
    if (k <= n) {
        cout << k << " 1\n";
    }
    else {
        k -= n;
        ll nr = (k - 1) / (m - 1) + 1;
        ll remain = k % (m - 1);
        ll x, y;

        x = n - nr + 1;
        y = k - (nr - 1) * (m - 1);
        if (nr & 1) {
            y++;
        }
        else {
            y = m - y + 1;
        }
        cout << x << " " << y << "\n";
    }
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    ll n, m, k;
    cin >> n >> m >> k;
    solve(n, m, k);
    // for (ll i = 0; i < n*m; i++) {
    //     solve(n, m, i);
    // }

    return 0;
}