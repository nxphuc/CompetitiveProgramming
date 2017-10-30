#include <bits/stdc++.h>
using namespace std;

const int MAX = 510;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int a[MAX][MAX];
int vis[MAX][MAX];
int h, w, u, v;
priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	cin >> u >> v;
	u--, v--;
	pq.push(make_pair(a[u][v], make_pair(u, v)));
	vis[u][v] = 1;
	pair<int,int> tmp;
	while (!pq.empty()) {
		tmp = pq.top().second;
		pq.pop();
		u = tmp.first;
		v = tmp.second;
		if (a[u][v] >= 0) {
			break;
		}
		for (int x, y, i = 0; i < 8; i++) {
			x = u + dx[i];
			y = v + dy[i];
			if (0 <= x && x < h && 0 <= y && y < w && !vis[x][y]) {
				a[x][y] = max(a[x][y], a[u][v]);
				vis[x][y] = 1;
				pq.push(make_pair(a[x][y], make_pair(x, y)));
			}
		}
	}
	long long res = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (vis[i][j] && a[i][j] < 0)
				res -= a[i][j];
		}
	}
	cout << res;

	return 0;
}