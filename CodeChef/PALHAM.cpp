// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// const int MAX = 3e5 + 10;
// const int MOD = 1e9 + 7;

// ll fact[MAX];
// ll sum_comb[MAX];

// ll fastPow(ll b, ll p) {
// 	if (!p) {
// 		return 1;
// 	}
// 	ll ret = fastPow(b, p/2);
// 	ret = (ret * ret) % MOD;
// 	if (p & 1) {
// 		ret = (ret * b) % MOD;
// 	}
// 	return ret;
// }

// ll combin(int n, int k) {
// 	ll res = (fact[n] * fastPow(fact[k], MOD - 2)) % MOD;
// 	return (res * fastPow(fact[n-k], MOD - 2)) % MOD;
// }

// ll numWays(ll n, ll k, ll num_diff) {
// 	if (k < 0) {
// 		return 0;
// 	}
// 	// if (!k) {
// 	// 	return 1;
// 	// }
// 	ll ret = 0;
// 	ll tmp;
// 	ll m = n - num_diff;

// 	sum_comb[0] = 1;
// 	for (int i = 1; i <= m; i++) {
// 		sum_comb[i] = (sum_comb[i-1] + combin(m, i)) % MOD;
// 	}
// 	// cout << "# " << n << " " << k << " " << num_diff << "\n";
// 	for (int i = 0; i <= num_diff && i <= k; i++) {
// 		tmp = fastPow(2, num_diff - i);
// 		tmp = (tmp * combin(num_diff, i)) % MOD;
// 		tmp = (tmp * 24LL) % MOD;
// 		tmp = (tmp * sum_comb[(k - i) / 2]) % MOD;
// 		ret = (ret + tmp) % MOD;
// 		// ret += (((24LL * combin(i, num_diff)) % MOD) * sum_comb[(k - i) / 2])  % MOD;
// 	}
// 	tmp = (23LL * fastPow(2, num_diff)) % MOD;
// 	ret = (ret - tmp + 2*MOD) % MOD;
// 	// cout << "## " << ret - 24 << "\n";
// 	return ret;
// 	// return (ret - 1 + 2*MOD) % MOD;
// }

// int main() {
// 	// freopen("test.in", "rt", stdin);
// 	ios::sync_with_stdio(false);

// 	fact[0] = 1;
// 	for (int i = 1; i <= 3e5; i++) {
// 		fact[i] = (fact[i-1] * i) % MOD;
// 	}

// 	int t, n, k;
// 	string s;

// 	cin >> t;
// 	while (t--) {
// 		cin >> n >> k;
// 		cin >> s;
// 		int flag = n & 1;
// 		int num_diff = 0;
// 		for (int i = 0, j = n-1; i < j; i++, j--) {
// 			num_diff += s[i] != s[j];
// 		}
// 		n /= 2;
// 		if (num_diff > k) {
// 			cout << "0\n";
// 			continue;
// 		}
// 		k -= num_diff;
// 		ll res = numWays(n, k, num_diff);
// 		// cout << "$ " << res << " " << k << " " << num_diff << "\n";
// 		// if (flag) {
// 			res = (res + 25*numWays(n, k-1, num_diff)) % MOD;
// 		// }
// 		// cout << "@ " << res << " " << flag << "\n";
// 		cout << res << "\n";
// 	}

// 	return 0;
// }