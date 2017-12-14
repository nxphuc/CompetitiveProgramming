#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;

int t, n, m;
int vis[MAX][MAX];
int h[MAX][MAX];
vector<pair<int,int>> cells;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int cmp(pair<int,int> lft, pair<int,int> rht) {
	return h[lft.first][lft.second] > h[rht.first][rht.second];
}

int inBoard(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void bfs(int u, int v) {
	queue<pair<int,int>> q;
	pair<int,int> cur;
	int x, y;

	vis[u][v] = 1;
	q.push(make_pair(u, v));
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		u = cur.first;
		v = cur.second;
		for (int i = 0; i < 4; i++) {
			x = u + dx[i];
			y = v + dy[i];
			if (inBoard(x, y) && !vis[x][y] && h[x][y] <= h[u][v]) {
				vis[x][y] = 1;
				q.push(make_pair(x, y));
			}
		}
	}
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cells.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> h[i][j];
				cells.push_back(make_pair(i, j));
			}
		}
		sort(cells.begin(), cells.end(), cmp);
		memset(vis, 0, sizeof(vis));
		int res = 0;
		for (auto cell : cells) {
			if (!vis[cell.first][cell.second]) {
				bfs(cell.first, cell.second);
				res++;
			}
		}
		cout << res << "\n";
	}

	return 0;
}