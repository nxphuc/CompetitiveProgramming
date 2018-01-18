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

	int t, n, x, mn, mx;
	cin >> t;
	while (t--) {
		int mn = 1010;
		int mx = -1;
		cin >> n;
		while (n--) {
			cin >> x;
			mn = min(mn, x);
			mx = max(mx, x);
		}
		cout << mx - mn << "\n";
	}
	
	return 0;
}