#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 2e12 + 10;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n;
	ll a[2010];

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			ll tmp, s = 0, lcm = 1;
			for (int j = i; j < n; j++) {
				s += a[j];
				tmp = a[j] / __gcd(lcm, a[j]);
				if (tmp > INF/lcm) {
					break;
				}
				lcm *= tmp;
				res += s % lcm == 0;
			}
		}
		cout << res << "\n";
	}

	return 0;
}