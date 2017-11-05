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
	vector<int> vis(n, -1);
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
	srand(time(NULL));
	int n = 100000;
	int m = 50000;
	int a = 20;
	cout << n << " " << m << " " << a << endl;
	for (int i = 1; i <= m; i++) {
		int x = i * 2;
		int y = x + 1;
		if (y > n) y = 1;
		int z = 1000000000;
		cout << x << " " << y << " " << z << endl;
	}
	
	return 0;
}