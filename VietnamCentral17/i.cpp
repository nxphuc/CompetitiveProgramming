#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	long long res = -1e18, s = 0;
	long long mn[3] = {0, (long long)1e18, (long long)1e18};
	int n;

	cin >> n;
	for (int x, i = 1; i <= n; i++) {
		cin >> x;
		s += x;
		res = max(res, s - mn[i % 3]);
		mn[i % 3] = min(mn[i % 3], s);
	}
	cout << res << "\n";

	return 0;
}