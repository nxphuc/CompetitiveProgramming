#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int INF = 1e9;
typedef long long ll;

int main() {
	// freopen("test", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n, k;

	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (k == 2) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << k-1-(i == n-1) << " ";
		}
		cout << "\n";
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << 1 + (i == j) << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}