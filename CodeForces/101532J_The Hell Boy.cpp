#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n;
	ll res, x;
	cin >> t;
	while (t--) {
		cin >> n;
		res = 0;
		while (n--) {
			cin >> x;
			res = (res * (x + 1) + x) % MOD;
		}
		cout << res << "\n";
	}

	return 0;
}