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

	int n;
	vector<pair<int,int>> edges;
	vector<int> times;

	cin >> n;
	for (int u, v, i = 0; i < n; i++) {
		cin >> u >> v;
		edges.push_back(make_pair(u, v));
		times.push_back(u);
		times.push_back(v);
	}
	sort(times.begin(), times.end());
	times.resize(unique(times.begin(), times.end()) - times.begin());

	int m = times.size();
	int lo = 0, hi = times[m - 1] - times[0];
	int mi, res = times[m - 1] - times[0];
	while (lo <= hi) {
		mi = (lo + hi) >> 1;

		PushRelabel flow(n + m + 1);
		for (int i = 0; i < n; i++) {
			flow.AddEdge(0, i + 1, mi);
			for (int j = 1; j < m; j++) {
				if (edges[i].first <= times[j - 1] && times[j] <= edges[i].second) {
					flow.AddEdge(i + 1, n + j, times[j] - times[j - 1]);
				}
			}
		}
		for (int i = 1; i < m; i++) {
			flow.AddEdge(i + n, n + m, times[i] - times[i-1]);
		}
		

		if (flow.GetMaxFlow(0, n + m) == mi*n) {
			res = mi * n;
			lo = mi + 1;
		}
		else {
			hi = mi - 1;
		}
	}
	cout << res << "\n";

	return 0;
}