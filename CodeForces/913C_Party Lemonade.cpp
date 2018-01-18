#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 40;
const int MOD = 1e9 + 7;
const ll INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

ll c[MAX];
ll f[MAX];
int n;
ll l;

ll calc(ll l) {
	if (l == 0) {
		return 0;
	}
	if (l == 1) {
		return c[0];
	}
	ll res = INF*INF;
	int i;
	for (i = 0; i < n; i++) {
		if (f[i] >= l) {
			res = min(res, c[i]);
			break;
		}
	}
	i--;
	res = min(res, c[i] * (l / f[i]) + calc(l % f[i]));
	return res;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	f[0] = 1;
	for (int i = 1; i < n; i++) {
		c[i] = min(c[i], c[i-1]*2LL);
		f[i] = f[i-1] << 1;
	}
	for (int i = n-2; i >= 0; i--) {
		c[i] = min(c[i], c[i+1]);
	}
	cout << calc(l);
	
	return 0;
}