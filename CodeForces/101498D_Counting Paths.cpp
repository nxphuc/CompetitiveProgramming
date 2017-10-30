#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;

ll fact[MAX];

ll fastPow(ll b, ll p) {
	if (!p) {
		return 1;
	}
	ll ret = fastPow(b, p >> 1);
	ret = (ret * ret) % MOD;
	if (p & 1) {
		ret = (ret * b) % MOD;
	}
	return ret;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t;
	ll n, k, res;

	fact[0] = 1;
	for (int i = 1; i < MAX; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
	cin >> t;
	while (t--) {
		cin >> n >> k;
		n--;
		res = (fact[n] * fastPow(fact[n-k], MOD-2)) % MOD;
		res = (res * fastPow(fact[k], MOD-2)) % MOD;
		cout << (2LL * res) % MOD << "\n";
	}

	return 0;
}