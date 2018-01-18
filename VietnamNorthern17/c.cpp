#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int INF = 1e9;
typedef long long ll;

int main() {
	// freopen("test", "rt", stdin);
	ios::sync_with_stdio(false);

	int t;
	ll a, n, lft, rht;

	cin >> t;
	while (t--) {
		cin >> a >> n;
		lft = a - a % n;
		rht = a + (n - a % n);
		cout << min((lft^a), (rht^a)) << "\n";;
	}

	return 0;
}