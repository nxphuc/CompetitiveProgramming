#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;

vector<int> divisors[MAX];
ll f[MAX][20];
ll fact[MAX], rev_fact[MAX];
int q, n, m;

ll dp(int n, int k) {
	if (f[n][k] != -1) {
		return f[n][k];
	}
	if (k == 1) {
		return f[n][1] = 1;
	}
	f[n][k] = 0;
	for (auto divisor : divisors[n]) {
		f[n][k] = (f[n][k] + dp(n / divisor, k - 1)) % MOD;
	}
	return f[n][k];
}

ll fastPow(ll b, ll p) {
	if (!p) {
		return 0;
	}
	ll ret = fastPow(b, p/2);
	ret = (ret * ret) % MOD;
	if (p & 1) {
		ret = (ret * b) % MOD;
	}
	return ret;
}

ll mult(ll a, ll b) {
	return (a * b) % MOD;
}

int main() {
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	for (int i = 2; i <= 1e6; i++) {
		for (int j = i; j <= 1e6; j += i) {
			divisors[j].push_back(i);
		}
	}
	fact[0] = 1;
	for (int i = 1; i < MAX; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		rev_fact[i] = (rev_fact[i-1] * fastPow(i, MOD - 2)) % MOD;
	}
	memset(f, -1, sizeof(f));
	f[1][0] = 1;
	
	cin >> q;
	while (q--) {
		cin >> n >> m;
		for (int i = 1; i <= log2(n); i++) {
			dp(n, i);
		}
		ll res = 0;
		for (int i = 1; i <= log2(n); i++) {
			if (i > m) {
				break;
			}
			ll tmp = mult(mult(fact[m], rev_fact[m - i]), rev_fact[i]);
			tmp = (tmp * fastPow(2, m-1)) % MOD;
			res += tmp;
		}
		cout << res << "\n";
	}

	return 0;
}