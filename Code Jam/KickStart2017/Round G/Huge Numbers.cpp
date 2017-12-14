#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fastPow(ll base, ll exp, ll mod) {
	if (!base) {
		return base;
	}
	if (!exp) {
		return 1 % mod;
	}
	ll res = fastPow(base, exp >> 1, mod);
	res = (res * res) % mod;
	if (exp & 1) {
		res = (res * base) % mod;
	}
	return res;
}

int main() {
	freopen("A-large-practice.in", "rt", stdin);
	freopen("A-large-practice.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int t, a, n, p;

	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		cin >> a >> n >> p;
		a %= p;
		for (int i = 2; i <= n; i++) {
			a = fastPow(a, i, p);
		}
		cout << "Case #" << cs << ": " << a << "\n";
	}

	return 0;
}