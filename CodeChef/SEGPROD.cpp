#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;

int a[MAX];
int b[MAX];
vector<int> primes;
map<int,int> fact[MAX];
vector<bool> mask(MAX, true);
int t, n, m, q, MOD, l, r, x;

void primeSieve() {
	mask[0] = mask[1] = false;
	for (int i = 2; i < MAX; i++) {
		if (mask[i]) {
			primes.push_back(i);
			for (ll j = 1LL * i * i; j < MAX; j += i) {
				mask[j] = false;
			}
		}
	}
}

void process(map<int,int>& fact, int n) {
	for (const int& p : primes) {
		if (p > n) {
			break;
		}
		int cnt = 0;
		while (n % p == 0) {
			n /= p;
			cnt++;
		}
		if (cnt) {
			fact[p] = cnt;
		}
	}
	if (n > 1) {
		fact[n] = 1;
	}
}

ll fastPow(int b, int p) {
	if (!p) {
		return 1;
	}
	ll ret = fastPow(b, p/2);
	ret = (ret * ret) % MOD;
	if (p & 1) {
		ret = (ret * b) % MOD;
	}
	return ret;
}

int query(int l, int r) {
	ll res = 1;
	for (const auto& kvp : fact[r]) {
		res = (res * fastPow(kvp.first, kvp.second - fact[l-1][kvp.first])) % MOD;
	}
	return res;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	primeSieve();
	// cout << "Done\n";

	cin >> t;
	while (t--) {
		cin >> n >> MOD >> q;
		for (int i = 1; i <= n; i++) {
			fact[i].clear();
			cin >> a[i];
			process(fact[i], a[i]);
			for (const auto& kvp : fact[i-1]) {
				fact[i][kvp.first] += kvp.second;
			}
		}

		m = q / 64 + 2;
		// cout << m << "\n";
		for (int i = 0; i < m; i++) {
			cin >> b[i];
			// cout << b[i] << " ";
		}

		// cout << "Done input " << t << "\n";

		x = 0;
		for (int i = 0; i < q; i++) {
			if (i % 64 == 0) {
				l = (b[i/64] + x) % n;
				r = (b[i/64 + 1] + x) % n;
			}
			else {
				l = (l + x) % n;
				r = (r + x) % n;
			}
			if (l > r) swap(l, r);
			x = query(l+1, r+1);
			x = (x + 1) % MOD;
		}
		cout << x << "\n";
	}

	return 0;
}