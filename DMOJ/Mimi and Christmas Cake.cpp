#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

int is_prime[MAX];

void primeSieve() {
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = is_prime[1] = 0;
	for (ll i = 2; i < MAX; i++) {
		if (is_prime[i]) {
			for (ll j = i*i; j < MAX; j += i) {
				is_prime[j] = 0;
			}
		}
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	primeSieve();
	int n, x, cnt = 0;
	cin >> n;
	while (n--) {
		cin >> x;
		cnt += is_prime[x] != 0;
	}
	cout << cnt;
	
	return 0;
}