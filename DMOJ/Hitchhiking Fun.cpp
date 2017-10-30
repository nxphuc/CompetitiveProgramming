#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int INF = 1e9;
typedef pair<pair<int,int>,int> Node;

vector<pair<int,int>> adj[MAX];
pair<int,int> dist[MAX];
int n, m;

void dijkstra() {
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	Node tmp, nxt;
	pair<int,int> d;

	for (int i = 1; i <= n; i++) {
		dist[i] = make_pair(INF, INF);
	}
	dist[1] = make_pair(0, 0);
	pq.push(make_pair(dist[1], 1));
	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();
		if (tmp.first != dist[tmp.second]) {
			continue;
		}
		if (tmp.second == n) {
			break;
		}
		for (const auto& nei : adj[tmp.second]) {
			d = make_pair(tmp.first.first + nei.second, tmp.first.second + 1);
			if (d < dist[nei.first]) {
				dist[nei.first] = d;
				pq.push(make_pair(d, nei.first));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	// cin >> n >> m;
	scanf("%d%d", &n, &m);
	for (int u, v, t, i = 0; i < m; i++) {
		// cin >> u >> v >> t
		scanf("%d%d%d", &u, &v, &t);
		adj[u].push_back(make_pair(v, t));
		adj[v].push_back(make_pair(u, t));
	}
	dijkstra();
	if (dist[n].first == INF) {
		// cout << -1;
		printf("-1");
	}
	else {
		printf("%d %d", dist[n].first, dist[n].second);
		// cout << dist[n].nDangerous << " " << dist[n].nRoads;
	}

	return 0;
}