#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 25010;
const ll INF = 2e14;

ll a[MAX][30], b[MAX][30];

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	pair<ll,ll> f[2][30];
	int t, n, m;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < m; j++) {
				cin >> b[i][j];
			}
		}

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j <= m; j++) {
				f[i][j] = make_pair(INF, INF);
			}
		}
		f[1][1] = make_pair(0, 0);
		for (int i = 2; i <= m; i++) {
			f[1][i] = make_pair(0, f[1][i-1].second + b[1][i-1]);
		}

		for (int cur, prv, i = 2; i <= n+1; i++) {
			cur = i & 1;
			prv = 1 - cur;
			for (int j = 1; j <= m; j++) {
				f[cur][j] = make_pair(f[prv][j].first + a[i-1][j], f[prv][j].second);
			}
			for (int j = 1; j <= m; j++) {
				ll bonus_second = 0;
				for (int k = j - 1; k > 0; k--) {
					bonus_second += b[i][k];
					f[cur][k] = min(f[cur][k], make_pair(f[cur][j].first, f[cur][j].second + bonus_second));
				}
				bonus_second = 0;
				for (int k = j + 1; k <= m; k++) {
					bonus_second += b[i][k - 1];
					f[cur][k] = min(f[cur][k], make_pair(f[cur][j].first, f[cur][j].second + bonus_second));
				}
			}
		}
		pair<ll, ll> res = make_pair(INF, INF);
		for (int i = 1; i <= m; i++) {
			res = min(res, f[(n + 1) & 1][i]);
		}
		cout << res.first << " " << res.second << "\n";
	}

	return 0;
}