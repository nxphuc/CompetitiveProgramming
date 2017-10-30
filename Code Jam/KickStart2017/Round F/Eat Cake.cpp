#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10;
const int INF = 1e9;

int f[MAX];

int dp(int n) {
	if (f[n] != -1) {
		return f[n];
	}
	if (n < 4) {
		return f[n] = n;
	}
	f[n] = INF;
	for (int i = 1; i*i <= n; i++) {
		f[n] = min(f[n], dp(n - i*i) + 1);
	}
	return f[n];
}

int main() {
	freopen("D-large.in", "rt", stdin);
	freopen("D-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int t, n;

	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		cin >> n;
		memset(f, -1, sizeof(f));
		cout << "Case #" << cs << ": " << dp(n) << "\n";
	}

	return 0;
}