#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e5 + 10;
const int INF = 1e9;

int n, m, c1, c2;
int a[MAX], b;
int min_dist = INF;
int cnt = 0;

void update(int x, int y, int u, int v) {
	if (min_dist > abs(x - u) + abs(y - v)) {
		min_dist = abs(x - u) + abs(y - v);
		cnt = 1;
	}
	else if (min_dist == abs(x - u) + abs(y - v)) {
		cnt++;
	}
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	cin >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i, j = 0; j < m; j++) {
		cin >> b;
		i = lower_bound(a, a+n, b) - a;
		if (i != 0) {
			update(a[i-1], c1, b, c2);
		}
		if (i != n) {
			update(a[i], c1, b, c2);
		}
	}
	cout << min_dist << " " << cnt << "\n";

	return 0;
}