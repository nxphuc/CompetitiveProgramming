#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 110;

struct Edge{
	int from, to, cap, flow, index;

	Edge(int from = 0, int to = 0, int cap = 0, int flow = 0, int index = 0)
		: from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
	int N;
	vector< vector<Edge> > G;
	vector<ll> excess;
	vector<int> dist, active, count;
	queue<int> Q;

	PushRelabel(int N = 0) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

	void AddEdge(int from, int to, int cap){
		G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
		if (from == to)
			G[from].back().index++;
		G[to].push_back(Edge(to, from, 0, 0, G[from].size()-1));
	}

	void Enqueue(int v){
		if (!active[v] && excess[v] > 0){
			active[v] = 1;
			Q.push(v);
		}
	}

	void Push(Edge& e){
		int amt = min(excess[e.from], (ll)(e.cap - e.flow));
		if (dist[e.from] <= dist[e.to] || !amt)
			return;
		e.flow += amt;
		G[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		Enqueue(e.to);
	}

	void Gap(int k){
		for (int v = 0; v < N; v++){
			if (dist[v] < k) continue;
			count[dist[v]]--;
			dist[v] = max(dist[v], N+1);
			count[dist[v]]++;
			Enqueue(v);
		}
	}

	void Relabel(int v){
		count[dist[v]]--;
		dist[v] = 2*N;
		for (int i = 0; i < G[v].size(); i++)
			if (G[v][i].cap - G[v][i].flow > 0)
				dist[v] = min(dist[v], dist[G[v][i].to] + 1);
		count[dist[v]]++;
		Enqueue(v);
	}

	void Discharge(int v){
		for (int i = 0; excess[v] > 0 && i < G[v].size(); i++)
			Push(G[v][i]);
		if (excess[v] > 0){
			if (count[dist[v]] == 1)
				Gap(dist[v]);
			else
				Relabel(v);
		}
	}

	ll GetMaxFlow(int s, int t){
		count[0] = N-1;
		count[N] = 1;
		dist[s] = N;
		active[s] = active[t] = 1;
		for (int i = 0; i < G[s].size(); i++){
			excess[s] += G[s][i].cap;
			Push(G[s][i]);
		}

		while (!Q.empty()){
			int v = Q.front();
			Q.pop();
			active[v] = 0;
			Discharge(v);
		}

		ll maxFlow = 0;
		for (int i = 0; i < G[s].size(); i++)
			maxFlow += G[s][i].flow;
		return maxFlow;
	}
};

vector<int> topo;
int used[MAX];
vector< vector<int> > graph;
vector< pair<int,int> > edges;
bitset<MAX> mask[MAX], tmp;
int t, n, m, k, u, v;

void dfs(int u){
	used[u] = 1;
	for (int v : graph[u])
		if (!used[v])
			dfs(v);
	topo.push_back(u);
}

void topoSort(){
	for (int i = 0; i < n; i++)
		if (!used[i])
			dfs(i);
	reverse(topo.begin(), topo.end());
}

void init(){
	topo.clear();
	graph.clear();
	edges.clear();
	memset(used, 0, sizeof(used));
}

void prepare(){
	topoSort();
	for (int i = 0; i < n; i++)
		mask[i].reset();
	mask[0].set(0);	
	for (int i = 0; i < topo.size(); i++){
		int u = topo[i];
		for (int v : graph[u])
			mask[v] |= (mask[u] << 1);
	}
}

int binarySearch(){
	int low = 0, high = n+1;
	int mid, cnt;
	int res = -1;

	while (low <= high){
		mid = (low + high) >> 1;
		PushRelabel flow(n);
		for (auto e: edges){
			cnt = 0;
			for (int i = 0; i < mid; i++)
				cnt += mask[e.first].test(i);
			flow.AddEdge(e.first, e.second, cnt);
			// cout << e.first << " " << e.second << " " << cnt << "\n";
		}
		// cout << low << " " << high << " " << flow.GetMaxFlow(0, n-1) << "\n";
		// return 0;
		if (flow.GetMaxFlow(0, n-1) >= k){
			res = mid;
			high = mid-1;
		}
		else
			low = mid+1;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif

	cin >> t;
	while (t--){
		init();
		
		cin >> n >> m >> k;

		graph.resize(n);
		while (m--){
			cin >> u >> v;
			--u, --v;
			edges.push_back(make_pair(u, v));
			graph[u].push_back(v);
		}
		prepare();
		cout << binarySearch() << "\n";
	}

	return 0;
}

