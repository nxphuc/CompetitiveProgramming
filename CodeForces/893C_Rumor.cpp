#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5 + 10;

pair<int,int> a[MAX];
vector<int> adj[MAX];
int vis[MAX];
int n, m;

void bfs(int s) {
	queue<int> q;
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		s = q.front();
		q.pop();
		for (auto nei : adj[s]) {
			if (!vis[nei]) {
				vis[nei] = 1;
				q.push(nei);
			}
		}
	}
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int u, v, i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sort(a + 1, a + n + 1);
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[a[i].second]) {
			res += a[i].first;
			bfs(a[i].second);
		}
	}
	cout << res;

	return 0;
}