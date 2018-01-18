#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int MAX = 1e6;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

ll f[MAX + 10];
unordered_map<ll, ll> f2;
vector<ll> p;

ll calc(ll n) {
	if (n <= MAX) {
		return f[n];
	}
	if (f2.find(n) != f2.end()) {
		return f2[n];
	}
	ll res = 0;
	for (const auto& x : p) {
		if (n % x == 0) {
			res = max(res, x * calc(n/x) + 1);
		}
	}
	f2[n] = res;
	return res;
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	f[1] = 1;
	for (int i = 1; i <= MAX; i++) {
		for (int j = 2; i*j <= MAX; j++) {
			f[i*j] = max(f[i*j], j*f[i] + 1);
		}
	}

	int n;
	ll a;
	ll res = 0;
	cin >> n;
	while (n--) {
		cin >> a;
		if (a <= MAX) {
			res += f[a];
		}
		else {
			p.clear();
			ll tmp = a;
			for (ll i = 2; i*i <= tmp; i++) {
				if (tmp % i == 0) {
					p.push_back(i);
					while (tmp % i == 0) {
						tmp /= i;
					}
				}
			}
			if (tmp != 1) {
				p.push_back(tmp);
			}
			res += calc(a);
		}
	}
	cout << res;
	
	return 0;
}