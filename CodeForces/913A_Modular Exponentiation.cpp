#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m;
	k = 1;
	for (int i = 1; i <= n; i++) {
		k <<= 1;
		if (m < k) {
			cout << m;
			return 0;
		}
	}
	cout << m % k;
	
	return 0;
}