#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    ll n, k;
    ll p[61];
    p[0] = 1;
    for (int i = 1; i <= 60; i++) {
        p[i] = p[i-1] * 2;
    }

    cin >> n >> k;
    map<ll, int> f;
    for (int i = 60; i >= 0; i--) {
        if (n >= p[i]) {
            f[i] = 1;
            n -= p[i];
        }
    }
    if (f.size() > k) {
        cout << "No";
        return 0;
    }
    k -= f.size();
    while (k) {
        ll x = f.rbegin()->first;
        int cnt = f.rbegin()->second;

        if (cnt <= k) {
            f[x - 1] += cnt * 2;
            k -= cnt;
            f.erase(x);
        }
        else {
            f[x - 1] += k * 2;
            f[x] -= k;
            k = 0;
        }
    }
    cout << "Yes\n";
    for (map<ll, int>::reverse_iterator rit = f.rbegin(); rit != f.rend(); rit++) {
        for (int i = 0; i < rit->second; i++) {
            cout << rit->first << " ";
        }
    }

    return 0;
}