#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;
const ll INF = 2e15;

vector<pair<int,int>> graph[MAX], rev_graph[MAX];
ll dist[MAX], rev_dist[MAX];
int n, m, k, s, t;

void dijkstra(std::vector<pair<int,int>> graph[], int src, ll dist[]) {
	for (int i = 0; i <= n; i++) {
		dist[i] = INF;
	}
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	int u;
	ll w;

	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty()) {
		u = pq.top().second;
		w = pq.top().first;
		pq.pop();
		if (dist[u] != w) {
			continue;
		}
		for (pair<int,int> nei : graph[u]) {
			if (dist[nei.first] > w + nei.second) {
				dist[nei.first] = w + nei.second;
				pq.push(make_pair(dist[nei.first], nei.first));
			}
		}
	}
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k >> s >> t;
	for (int u, v, w, i = 0; i < m; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		rev_graph[v].push_back(make_pair(u, w));
	}
	dijkstra(graph, s, dist);
	dijkstra(rev_graph, t, rev_dist);
	ll res = dist[t];
	for (int u, v, w, i = 0; i < k; i++) {
		cin >> u >> v >> w;
		// cout << res << " " << dist[u] << " " << rev_dist[v] << " " << w << "\n";
		res = min(res, dist[u] + rev_dist[v] + w);
		res = min(res, dist[v] + rev_dist[u] + w);
	}
	cout << (res < INF ? res : -1);

	return 0;
}