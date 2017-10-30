#include <bits/stdc++.h>
using namespace std;

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

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, m;
	vector<pair<int,int>> edges, ans;

	cin >> n >> m;
	for (int u, v, i = 1; i <= m; i++) {
		cin >> u >> v;
		edges.push_back(make_pair(u, v));
	}
	ans.resize(m);

	int lo = 0, hi = n;
	int mi, res = n;
	while (lo <= hi) {
		mi = (lo + hi) >> 1;

		PushRelabel flow(n + m + 2);
		for (int i = 0; i < m; i++) {
			flow.AddEdge(0, i + 1, 1);
			flow.AddEdge(i + 1, edges[i].first + m, 1);
			flow.AddEdge(i + 1, edges[i].second + m, 1);
		}
		for (int i = 1; i <= n; i++) {
			flow.AddEdge(i + m, n + m + 1, mi);
		}

		if (flow.GetMaxFlow(0, n + m + 1) == m) {
			res = mi;
			hi = mi - 1;
			for (int i = 1; i <= m; i++) {
				for (auto& e : flow.G[i]) {
					if (e.to == 0) {
						continue;
					}
					if (e.flow == 1) {
						ans[i-1].first = e.to - m;
					}
					else {
						ans[i-1].second = e.to - m;
					}
					// cout << e.from << " " << e.to << " " << e.flow << " " << e.cap << " " << e.index << "\n";
				}
				// cout << "-----\n";
			}
		}
		else {
			lo = mi + 1;
		}
	}
	cout << res << "\n";
	for (auto& e: ans) {
		cout << e.first << " " << e.second << "\n";
	}

	return 0;
}