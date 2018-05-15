// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// const int MAX = 1e5 + 10;
// const int MOD = 1e9 + 7;

// ll fib[MAX];
// ll a[MAX], b[MAX];
// int n, m, t;

// ll mult(ll a, ll b) {
//     if (!b) {
//         return 0;
//     }
//     ll ret = mult(a, b / 2);
//     ret = (ret + ret) % MOD;
//     if (b & 1) {
//         ret = (ret + a) % MOD;
//     }
//     return ret;
// }

// int main() {
//     // freopen("test.in", "rt", stdin);
//     ios::sync_with_stdio(false);

//     fib[1] = 0;
//     fib[2] = 1;
//     for (int i = 3; i < MAX; i++) {
//         fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
//     }

//     cin >> t;
//     while (t--) {
//         cin >> m >> n;
//         b[0] = 0;
//         for (int i = 1; i <= m; i++) {
//             cin >> a[i];
//         }
//         for (int i = 1; i <= m; i++) {
//             cin >> b[i];
//             b[i] = (b[i - 1] + b[i]) % MOD;
//         }
//         ll res = 0;
//         n = max(2, n);
//         for (int i = 1; i <= m; i++) {
//             // cout << mult(a[i], fib[n - 1]) + mult(fib[n], b[m]) << "\n";
//             res = (res + mult(mult(a[i], fib[n - 1]), n) + mult(fib[n], b[m])) % MOD;
//         }
//         cout << res << "\n";
//     }

//     return 0;
// }