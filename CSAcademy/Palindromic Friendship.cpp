#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int n, m;
set<int> fr[MAX];

int numFriends(int l, int r) {
	while (l > 0 && r <= n && fr[l].find(r) != fr[l].end()) {
		l--;
		r++;
	}
	// cout << l << " " << r << " " << r - l - 1 << "\n";
	return r - l - 1;
}

int main() {
	cin >> n >> m;
	for (int u, v, i = 0; i < m; i++) {
		cin >> u >> v;
		if (u > v) {
			swap(u, v);
		}
		fr[u].insert(v);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, numFriends(i, i+1));
		res = max(res, numFriends(i, i+2));
	}
	cout << res;
	return 0;
}