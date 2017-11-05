#include <bits/stdc++.h> 

using namespace std; 

typedef unsigned long long ull;

const double EPS = 0.0000001;
const int MAX = 2e5 + 10;

struct Edge {
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}

	bool operator<(const Edge& other) {
		return w < other.w;
	}
};

int n, m;
ull alpha;
int par[MAX];
vector<int> adj[MAX];
vector<Edge> edges;
vector<Edge> edges2;

int findSet(int u) {
	return par[u] = par[u] == u ? u : findSet(par[u]);
}

ull getDist(int u, int v, ull w) {
	vector<int> vis(n+10, -1);
	queue<int> q;
	q.push(u);
	vis[u] = 0;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int nei : adj[u]) {
			if (vis[nei] == -1) {
				vis[nei] = vis[u] + 1;
				q.push(nei);
			}
		}
		if (vis[v] != -1) {
			break;
		}
	}
	return w*w + alpha*(vis[v] + 1);
}

int main () { 
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m >> alpha;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	int cnt = n;
	edges.resize(m);
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}
	sort(edges.begin(), edges.end());
	for (const Edge& edge : edges) {
		int u = findSet(edge.u);
		int v = findSet(edge.v);
		if (u != v) {
			adj[edge.u].push_back(edge.v);
			adj[edge.v].push_back(edge.u);
			par[v] = u;
			cnt--;
		}
		else {
			edges2.push_back(edge);
		}
	}
	if (edges2.size() == 0) {
		cout << "Poor girl";
		return 0;
	}
	ull res = -1;
	for (int i = 0; i < edges2.size(); i++) {
		if (i > 50) {
			break;
		}
		res = min(res, getDist(edges2[i].u, edges2[i].v, edges2[i].w));
		adj[edges2[i].u].push_back(edges2[i].v);
		adj[edges2[i].v].push_back(edges2[i].u);
	}
	cout << res << "\n";
	
	return 0;
}