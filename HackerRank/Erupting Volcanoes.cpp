#include <bits/stdc++.h>
using namespace std;

const int MAX = 310;

int a[MAX][MAX];
int n;

int dist(const int& x, const int& y, const int& u, const int& v) {
	return max(abs(x - u), abs(y - v));
}

void process(const int& x, const int& y, const int& w) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] += max(w - dist(x, y, i, j), 0);
		}
	}
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int m, x, y, w;

	cin >> n >> m;
	while (m--) {
		cin >> x >> y >> w;
		process(x, y, w);
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res = max(res, a[i][j]);
		}
	}
	cout << res;

	return 0;
}