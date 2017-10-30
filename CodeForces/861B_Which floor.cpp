#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	pair<int,int> a[110];

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i].first >> a[i].second;
	}
	int res = -1;
	for (int i = 1; i <= 100; i++) {
		int is_valid = 1;
		for (int j = 0; j < m; j++) {
			if (i*a[j].second < a[j].first || i*(a[j].second - 1) >= a[j].first ) {
				is_valid = 0;
				break;
			}
		}
		if (is_valid) {
			if (res == -1) {
				res = (n - 1)/i + 1;
			}
			else if (res != (n - 1) / i + 1) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << res << "\n";

	return 0;
}