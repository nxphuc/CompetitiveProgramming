#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int cnt_row[1010][3], cnt_col[1010][3];
	string s[1010];
	int t, n, m;

	cin >> t;
	while (t--) {
		cin >> n >> m;

		memset(cnt_row, 0, sizeof(cnt_row));
		memset(cnt_col, 0, sizeof(cnt_col));
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cnt_row[i][s[i][j] - '0']++;
				cnt_col[j][s[i][j] - '0']++;
			}
		}
		long long res = 0;
		for (int id, i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][j] != '0') {
					id = 3 - (s[i][j] - '0');
					res += 1LL * cnt_row[i][id] * cnt_col[j][id];
				}
			}
		}
		cout << res << "\n";
	}

	return 0;
}