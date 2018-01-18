#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

vector<int> primes;

void primeSieve() {
	vector<int> mask(MAX, 1);
	for (ll i = 2; i < MAX; i++) {
		if (mask[i]) {
			primes.push_back((int)i);
			for (ll j = i*i; j < MAX; j += i) {
				mask[j] = 0;
			}
		}
	}
}

ll divMod(ll a, ll b, ll m) {
	return ((a % (b * m)) / b) % m;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<ll> f(n+1);
	f[0] = f[n] = 1;
	if (n > 1) {
		f[1] = f[n-1] = n;
		for (int i = 2, j = n-2; i <= j; i++, j--) {
			f[i] = f[j] = ((1LL+n-i) * divMod(f[i-1], i, m)) % m;
		}
	}
	for (int i = 0; i <= n; i++) {
		cout << f[i] << "\n";
	}
	
	return 0;
}