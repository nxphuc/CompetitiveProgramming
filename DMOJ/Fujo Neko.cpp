#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;

int rows[MAX];
int cols[MAX];
char s[MAX];

int main() {
	ios::sync_with_stdio(false);
	int n, m, q, x, y;
	// string s;

	// cin >> n >> m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		// cin >> s;
		scanf("%s", s);
		for (int j = 1; j <= m; j++) {
			rows[i] |= s[j-1] == 'X';
			cols[j] |= s[j-1] == 'X';
		}
	}
	// cin >> q;
	scanf("%d", &q);
	while (q--) {
		// cin >> x >> y;
		scanf("%d%d", &x, &y);
		swap(x, y);
		// cout << (rows[x] || cols[y] ? "Y\n" : "N\n");
		printf("%s", (rows[x] || cols[y] ? "Y\n" : "N\n"));
	}
	return 0;
}