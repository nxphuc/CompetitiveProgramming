#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow {
	int N;
	VVL cap, flow, cost;
	VI found;
	VL dist, pi, width;
	VPII dad;

	MinCostMaxFlow(int N) : 
		N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)), 
		found(N), dist(N), pi(N), width(N), dad(N) {}
	
	void AddEdge(int from, int to, L cap, L cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
	}
	
	void Relax(int s, int k, L cap, L cost, int dir) {
		L val = dist[s] + pi[s] - pi[k] + cost;
		if (cap && val < dist[k]) {
			dist[k] = val;
			dad[k] = make_pair(s, dir);
			width[k] = min(cap, width[s]);
		}
	}

	L Dijkstra(int s, int t) {
		fill(found.begin(), found.end(), false);
		fill(dist.begin(), dist.end(), INF);
		fill(width.begin(), width.end(), 0);
		dist[s] = 0;
		width[s] = INF;
		
		while (s != -1) {
			int best = -1;
			found[s] = true;
			for (int k = 0; k < N; k++) {
				if (found[k]) continue;
				Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
				Relax(s, k, flow[k][s], -cost[k][s], -1);
				if (best == -1 || dist[k] < dist[best]) best = k;
			}
			s = best;
		}

		for (int k = 0; k < N; k++)
			pi[k] = min(pi[k] + dist[k], INF);
		return width[t];
	}

	pair<L, L> GetMaxFlow(int s, int t) {
		L totflow = 0, totcost = 0;
		while (L amt = Dijkstra(s, t)) {
			totflow += amt;
			for (int x = t; x != s; x = dad[x].first) {
				if (dad[x].second == 1) {
					flow[dad[x].first][x] += amt;
					totcost += amt * cost[dad[x].first][x];
				} else {
					flow[x][dad[x].first] -= amt;
					totcost -= amt * cost[x][dad[x].first];
				}
			}
		}
		return make_pair(totflow, totcost);
	}
};

vector <pair<int, int> > v;
int n, m;
char s[109][109]; 

int main() {
	freopen("test.in", "rt", stdin);
	scanf("%d %d", &n, &m); 
	for (int i = 0; i < n; i++) 
		scanf("%s", s[i]); 
	// int cnt = 0;  
	for (int i = 0; i <n; i++) 
		for (int j = 0; j < m; j++) { 
			if (s[i][j] == '#') 
				v.push_back(make_pair(i, j)); 
		}
	// init(n + m + 2 + v.size());
	// x, y, cap, cost 
	int src = 0;  
	int des = 1;
	MinCostMaxFlow mcmf(n+m+2+v.size());
	// add rows 
	for (int i = 0; i < n; i++) { 
		// add_edge(src, i + 2, INF, 1); 
		mcmf.AddEdge(src, i + 2, INF, 1);
	}
	// add cols 
	for (int i = 0; i < m; i++) {
		// add_edge(src, i + 2 + n, INF, 1);
		mcmf.AddEdge(src, i + 2 + n, INF, 1);
	}

	// add #
	for (int i = 0; i < v.size(); i++) { 
		// add_edge(i + 2 + n + m, des, 1, 0);
		mcmf.AddEdge(i + 2 + n + m, des, 1, 0);
		// add_edge(2 + v[i].first, i + 2 + n + m, 1, 0); 
		mcmf.AddEdge(2 + v[i].first, i + 2 + n + m, 1, 0);
		// add_edge(2 + n + v[i].second, i + 2 + n + m, 1, 0); 
		mcmf.AddEdge(2 + n + v[i].second, i + 2 + n + m, 1, 0);
	}

	int cost = 0;
	pair<L, L> res = mcmf.GetMaxFlow(src, des);
	cout << res.first << " " << res.second <<"\n";
	return 0;
}