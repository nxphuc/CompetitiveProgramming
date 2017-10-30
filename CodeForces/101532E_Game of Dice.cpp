#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

void rec(int i, int n, ll val, ll a[10][6], map<ll, ll>& ways) {
	if (i == n) {
		ways[val]++;
		return;
	}
	for (int j = 0; j < 6; j++) {
		rec(i+1, n, (val * a[i][j]) % MOD, a, ways);
	}
}

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

ll fastMod(ll a, ll b) {
	return (a * fastPow(b, MOD-2)) % MOD;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	ll a[2][10][6];
	int t, n, m, x;
	map<ll, ll> ways1, ways2;

	cin >> t;
	while (t--) {
		cin >> n >> x;
		ways1.clear();
		ways2.clear();
		m = n / 2;
		n -= m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 6; j++) {
				cin >> a[0][i][j];
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 6; j++) {
				cin >> a[1][i][j];
			}
		}
		rec(0, n, 1, a[0], ways1);
		rec(0, m, 1, a[1], ways2);
		ll res = 0;
		for (const auto& kvp : ways1) {
			res += kvp.second * ways2[fastMod(x, kvp.first)];
		}
		cout << res << "\n";
	}

	return 0;
}