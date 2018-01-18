#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

ll lo, hi, res;
int n, m, k;
ll a[MAX];
ll f[MAX];

int canIncrease(ll h) {
	memset(f, 0, (2*n + 10) * sizeof(ll));
	ll s = 0;
	ll need = 0;
	for (int i = 1; i <= n; i++) {
		s += f[i];
		if (a[i] + s < h) {
			ll tmp = h - a[i] - s;
			f[i + m] -= tmp;
			s += tmp;
			need += tmp;
		}
	}
	// if (h <= 10) {
	// 	cout << "# " << h << "\n";
	// 	for (int i = 0; i < 2*n + 10; i++) {
	// 		cout << f[i] << " ";
	// 	}
	// 	cout << "\n";
	// }
	return need <= k;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	lo = hi = 2LL*INF;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		lo = min(lo, a[i]);
	}
	res = lo;
	while (lo <= hi) {
		ll mi = lo + (hi - lo) / 2;
		if (canIncrease(mi)) {
			res = mi;
			lo = mi + 1;
		}
		else {
			hi = mi - 1;
		}
	}
	cout << res << "\n";

	return 0;
}