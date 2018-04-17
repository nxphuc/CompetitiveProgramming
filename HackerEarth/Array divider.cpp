#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, k;

    cin >> n >> k;

    vector<int> a(n + 1);
    vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int r = 1; r <= n; r++) {
            for (int l = 1; l <= r; l++) {
                long long tmp = a[r] - a[l - 1];
                dp[i][r] = min(dp[i][r], dp[i - 1][l - 1] + tmp*tmp*(k - 1) - 2LL*tmp*a[l - 1]);
            }
        }
    }
    cout << dp[k][n];

    return 0;
}