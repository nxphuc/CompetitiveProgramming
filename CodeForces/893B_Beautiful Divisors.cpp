#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, m, res = 1;
	cin >> n;
	for (int k = 1; k <= 10; k++) {
		m = 1;
		for (int j = 0; j < k; j++) {
			m = m << 1 | 1;
		}
		for (int j = 0; j < k; j++) {
			m <<= 1;
		}
		if (n < m) {
			break;
		}
		if (n % m == 0) {
			res = max(res, m);
		}
	}
	cout << res;

	return 0;
}