#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define pb push_back

const int MAX = 1e6 + 10;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

map<ll, int> f;
ll a, b;
vector<ll> v;

ll solve(ll x)
{ 
	ll hihi = x;
	f.clear();
	f[x] = 1;
	ll pos = 1;
	while (1) {
		if (x == 0) return 0;
		if (a % x != 0) return 0;
		pos++;
		ll nxt_x = a / x + b; 
		if (f.count(nxt_x)) {
			return pos - f[nxt_x];
		}
		f[nxt_x] = pos;
		x = nxt_x;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> a >> b;
	if (a == 0) {
		if (b == 0) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
		return 0;
	}
	for (int i = 1; i <= sqrt(abs(a)); i++) {
		if (a % i == 0) {
			v.pb(i);
			v.pb(-i);
			if (a / i != i) {
				v.pb(a / i);
				v.pb(-a / i);
			}
		}
	}
	ll ans = 0;
	for (auto x : v) { 
		ans = max(ans, solve(x));
	}
	cout << ans << endl;
	return 0;
}