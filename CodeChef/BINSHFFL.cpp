#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int calc(ll a, ll b) {
    if (a == b) {
        return 0;
    }
    b--;
    int n_bit_a = __builtin_popcountll(a);
    int n_bit_b = __builtin_popcountll(b);
    if (n_bit_a > n_bit_b) {
        return 2;
    }
    return n_bit_b - n_bit_a + 1;
}

int main() {
    freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    ll a, b;

    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << calc(a, b) << "\n";
    }

    return 0;
}