#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, ll> my_map;

void prepare(ll n) {
    ll val = n, pos = n * 2 - 1;
    ll step = 1;
    while (pos > step) {
        pos -= step;
        step *= 2;
    }
    cout << step << " " << pos << "\n";
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    ll n;
    int q;
    // cin >> n >> q;
    // prepare(n);
    prepare(20);
    prepare(27);

    return 0;
}