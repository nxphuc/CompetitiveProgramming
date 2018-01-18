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

	int t;
	ll y, res = 0;

	cin >> t;
	while (t--) {
		cin >> y;
		res = 0;
		for (ll b = 1; b <= 700; b++) {
			res += max(0, (int)sqrt(y-b));
		}
		// for (ll a = 1; a*a < y; a++) {
		// 	res += min(y - a*a, 700LL);
		// }
		cout << res << "\n";
	}
	
	return 0;
}