#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

struct Edge1 {
	int vertex1;
	int vertex2;
	int color;

	Edge1(int vertex1 = 0, int vertex2 = 0, int color = 0) : vertex1(vertex1), vertex2(vertex2), color(color) {}
};

typedef long long ll;

struct Edge {
	int from, to, cap, flow, index;
	Edge(int from, int to, int cap, int flow, int index)
		: from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
	int N;
	vector<vector<Edge> > G;
	vector<ll> excess;
	vector<int> dist, active, count;
	queue<int> Q;
	PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

	void AddEdge(int from, int to, int cap) {
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if (from == to) {
			G[from].back().index++;
		}
		G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
	}

	void Enqueue(int v) {
		if (!active[v] && excess[v] > 0) {
			active[v] = true;
			Q.push(v);
		}
	}

	void Push(Edge &e) {
		int amt = int(min(excess[e.from], ll(e.cap - e.flow)));
		if (dist[e.from] <= dist[e.to] || amt == 0)
			return;
		e.flow += amt;
		G[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		Enqueue(e.to);
	}

	void Gap(int k) {
		for (int v = 0; v < N; v++) {
			if (dist[v] < k)
				continue;
			count[dist[v]]--;
			dist[v] = max(dist[v], N+1);
			count[dist[v]]++;
			Enqueue(v);
		}
	}

	void Relabel(int v) {
		count[dist[v]]--;
		dist[v] = 2*N;
		for (int i = 0; i < G[v].size(); i++){
			if (G[v][i].cap - G[v][i].flow > 0) {
				dist[v] = min(dist[v], dist[G[v][i].to] + 1);
			}
		}
		count[dist[v]]++;
		Enqueue(v);
	}

	void Discharge(int v) {
		for (int i = 0; excess[v] > 0 && i < G[v].size(); i++)
			Push(G[v][i]);
		if (excess[v] > 0) {
			if (count[dist[v]] == 1)
				Gap(dist[v]);
			else
				Relabel(v);
		}
	}

	ll GetMaxFlow(int s, int t) {
		count[0] = N-1;
		count[N] = 1;
		dist[s] = N;
		active[s] = active[t] = true;
		for (int i = 0; i < G[s].size(); i++) {
			excess[s] += G[s][i].cap;
			Push(G[s][i]);
		}
		while (!Q.empty()) {
			int v = Q.front();
			Q.pop();
			active[v] = false;
			Discharge(v);
		}
		ll totflow = 0;
		for (int i = 0; i < G[s].size(); i++)
			totflow += G[s][i].flow;
		return totflow;
	}
};

vector<Edge1> edges;
vector<int> adj[MAX];
vector<map<int,int>> cyc;
int par[MAX];
int vis[MAX];
int n, m, maxC;

void addCycle(int v, int id) {
	int u = v == edges[id].vertex1 ? edges[id].vertex2 : edges[id].vertex1;
	map<int,int> cnt;
	cnt[edges[id].color] = 1;
    edges[id] = Edge1(-1, -1, 0);
	while (v != u) {
		id = par[v];
		cnt[edges[id].color]++;
		v = v == edges[id].vertex1 ? edges[id].vertex2 : edges[id].vertex1;
		edges[id] = Edge1(-1, -1, 0);
	}
	cyc.push_back(cnt);
}

void dfs(int u, int p) {
	vis[u] = 1;
	for (int v, c, i = 0; i < adj[u].size(); i++) {
		if (adj[u][i] == p) {
			continue;
		}
		v = edges[adj[u][i]].vertex1 == u ? edges[adj[u][i]].vertex2 : edges[adj[u][i]].vertex1;
		if (v == -1) {
			continue;
		}
		if (vis[v]) {
			addCycle(u, adj[u][i]);
		}
		else {
			par[v] = adj[u][i];
			dfs(v, adj[u][i]);
			if (edges[adj[u][i]].vertex1 != -1) {
				map<int,int> tmp;
				tmp[edges[adj[u][i]].color] = 2;
				cyc.push_back(tmp);
			}
		}
	}
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int u, v, c, i = 0; i < m; i++) {
		cin >> u >> v >> c;
		edges.push_back(Edge1(u, v, c));
		maxC = max(maxC, c);
		adj[u].push_back(edges.size() - 1);
		adj[v].push_back(edges.size() - 1);
	}
	memset(par, -1, sizeof(par));
	dfs(1, -1);

	// for (const auto& m : cyc) {
	// 	for (const auto& e : m) {
	// 		cout << e.first << " " << e.second << "\n";
	// 	}
	// 	cout << "================\n";
	// }


	PushRelabel flow(cyc.size() + maxC + 2);
	int k = cyc.size();
	for (int i = 0; i < k; i++) {
		int cnt = 0;
		for (const auto& e : cyc[i]) {
			cnt += e.second;
			flow.AddEdge(i + 1, e.first + k, 1);
		}
		flow.AddEdge(0, i + 1, cnt - 1);
	}
	for (int i = 1; i <= maxC; i++) {
		flow.AddEdge(i + k, k + maxC + 1, 1);
	}
	cout << flow.GetMaxFlow(0, k + maxC + 1);

	return 0;
}
