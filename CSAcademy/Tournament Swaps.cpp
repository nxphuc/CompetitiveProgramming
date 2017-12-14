#include <bits/stdc++.h>
using namespace std;

const int MAX = 18;

int t, n, m;
int f[MAX];
int a[1 << MAX];

set<int> getMin(int level, int l, int r) {
	set<int> min_set;
	if (l == r) {
		f[level] = min(a[l], f[level]);
		min_set.insert(a[l]);
	}
	else {
		min_set = getMin(level - 1, l, (l + r) / 2);
		set<int> tmp = getMin(level - 1, (l + r) / 2 + 1, r);
		for (int val : tmp) {
			min_set.insert(val);
		}
		while (min_set.size() > 2) {
			min_set.erase(min_set.begin());
		}
		f[level] = min(f[level], *min_set.begin());
	}
	return min_set;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		m = 1 << n;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < MAX; i++) {
			f[i] = 1 << MAX;
		}
		getMin(n, 0, m-1);
		// for (int i = 1; i <= n; i++) {
		// 	cout << f[i] << " ";
		// }
		// cout << "\n";
		for (int i = 1; i <= m; i++) {
			cout << lower_bound(f+1, f+n+1, i) - f - 1 << " ";
		}
		cout << "\n";
	}

	return 0;
}