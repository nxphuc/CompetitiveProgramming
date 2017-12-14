#include <bits/stdc++.h>
using namespace std;

int calculate(const vector<string>& s, int n, int m, char ch, int cost) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) & 1) {
				res += (8 - cost) * (s[i][j] == ch);
			}
			else {
				res += cost * (s[i][j] != ch);
			}
		}
	}
	return res;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n, m;
	vector<string> s;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		s.resize(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];

		cout << min(calculate(s, n, m, 'R', 3), calculate(s, n, m, 'G', 5)) << "\n";
	}

	return 0;
}