#include <bits/stdc++.h>
using namespace std;

const int MAX = 110;
const int INF = 1e9;
const long double EPS = 1e-9;
const long double ONE = 1;

int dist[MAX][MAX];
long double f[2][MAX];
int n, m, p;

void floydWarshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
	// freopen("C-small-attempt0.in", "rt", stdin);
	// freopen("C-small-attempt02.ou", "wt", stdout);
	freopen("test.in", "rt", stdin);
	freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int t;

	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		cin >> n >> m >> p;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = i == j ? 0 : INF;
			}
		}
		for (int u, v, d, i = 0; i < m; i++) {
			cin >> u >> v >> d;
			dist[u][v] = dist[v][u] = d;
		}
		floydWarshall();

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = -1;
			}
		}
		f[0][1] = 0;
		for (int cur, prv, i = 1; i <= p; i++) {
			cur = i & 1;
			prv = 1 - cur;
			for (int j = 1; j <= n; j++) {
				f[cur][j] = -1;
			}
			for (int j = 1; j <= n; j++) {
				if (fabs(f[prv][j] + 1) <= EPS) {
					continue;
				}
				for (int k = 1; k <= n; k++) {
					if (j != k) {
						if (fabs(f[cur][k] + 1) <= EPS) {
							f[cur][k] = 0;
						}
						f[cur][k] += (f[prv][j] + ONE * dist[j][k] / pow(n - ONE, i - ONE)) / (n - ONE);
					}
				}
			}
			int flag = 1;
			for (int i = 1; i <= n; i++) {
				if (fabs(f[cur][i] - f[prv][i]) > EPS) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				cerr << "# " << cs << " " << i << "\n";
				break;
			}
		}
		long double res = 0;
		for (int i = 1; i <= n; i++) {
			if (fabs(f[p & 1][i] + 1) <= EPS) {
				continue;
			}
			res += f[p & 1][i];
		}

		cout << "Case #" << cs << ": " << fixed << setprecision(6) << res << "\n";
	}
	return 0;
}
