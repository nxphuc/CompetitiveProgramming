#include <bits/stdc++.h> 

using namespace std;

const int maxv = 1000;
const int maxe = 50000;

struct EdmondsLawler {
	int n, E, start, finish, newRoot, qsize, adj[maxe], next[maxe], last[maxv], mat[maxv], que[maxv], dad[maxv], root[maxv];
	bool inque[maxv], inpath[maxv], inblossom[maxv];

	void init(int _n) {
		n = _n; E = 0;
		for(int x=1; x<=n; ++x) { last[x] = -1; mat[x] = 0; }
	}
	void addEdge(int u, int v) {
		adj[E] = v; next[E] = last[u]; last[u] = E++;
	}
	int lca(int u, int v) {
		for(int x=1; x<=n; ++x) inpath[x] = false;
		while (true) {
			u = root[u];
			inpath[u] = true;
			if (u == start) break;
			u = dad[mat[u]];
		}
		while (true) {
			v = root[v];
			if (inpath[v]) break;
			v = dad[mat[v]];
		}
		return v;
	}
	void trace(int u) {
		while (root[u] != newRoot) {
			int v = mat[u];

			inblossom[root[u]] = true;
			inblossom[root[v]] = true;

			u = dad[v];
			if (root[u] != newRoot) dad[u] = v;
		}
	}
	void blossom(int u, int v) {
		for(int x=1; x<=n; ++x) inblossom[x] = false;

		newRoot = lca(u, v);
		trace(u); trace(v);

		if (root[u] != newRoot) dad[u] = v;
		if (root[v] != newRoot) dad[v] = u;

		for(int x=1; x<=n; ++x) if (inblossom[root[x]]) {
			root[x] = newRoot;
			if (!inque[x]) {
				inque[x] = true;
				que[qsize++] = x;
			}
		}
	}
	bool bfs() {
		for(int x=1; x<=n; ++x){
			inque[x] = false;
			dad[x] = 0;
			root[x] = x;
		}
		qsize = 0;
		que[qsize++] = start;
		inque[start] = true;
		finish = 0;

		for(int i=0; i<qsize; ++i) {
			int u = que[i];
			for (int e = last[u]; e != -1; e = next[e]) {
				int v = adj[e];
				if (root[v] != root[u] && v != mat[u]) {
					if (v == start || (mat[v] > 0 && dad[mat[v]] > 0)) blossom(u, v);
					else if (dad[v] == 0) {
						dad[v] = u;
						if (mat[v] > 0) que[qsize++] = mat[v];
						else {
							finish = v;
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	void enlarge() {
		int u = finish;
		while (u > 0) {
			int v = dad[u], x = mat[v];
			mat[v] = u;
			mat[u] = v;
			u = x;
		}
	}

	int maxmat() {
		for(int x=1; x<=n; ++x) if (mat[x] == 0) {
			start = x;
			if (bfs()) enlarge();
		}

		int ret = 0;
		for(int x=1; x<=n; ++x) if (mat[x] > x) ++ret;
		return ret;
	}
};

int main () { 
	// freopen("test", "r", stdin);  
	int n, k; 

	scanf("%d %d", &n, &k);

	n *= 2;
	EdmondsLawler edmon;
	edmon.init(n);

	for (int i = 1; i <= k ; i++) { 
		int x, y;
		scanf("%d %d", &x, &y);
		edmon.addEdge(x, y);
		edmon.addEdge(y, x);
	}

	int ans = edmon.maxmat();
	vector<int> teams(n);
	set<int> vis;
	int l = 0, r = n-1;
	for (int i = 1; i <= n ; i++) {
		if (edmon.mat[i] > i && vis.find(i) == vis.end() && vis.find(edmon.mat[i]) == vis.end()) {
			teams[l++] = i;
			teams[r--] = edmon.mat[i];
			vis.insert(i);
			vis.insert(edmon.mat[i]);
		}
	}
	// assert(n - r + l - 1 == ans);
	for (int i = 1; i <= n ; i++) 
		if (vis.find(i) == vis.end()) {
			teams[l++] = i;
		}
	vector < vector < pair <int, int > > > res (n); 
	for (int i = 0; i < n - 1; i++) {
		for (int l = 0, r = n-1; l < r; l++, r--) {
			res[i].push_back(make_pair(teams[l], teams[r]));
		}
		int tmp = teams[1];
		for (int i = 1; i < n-1; i++) {
			teams[i] = teams[i+1];
		}
		teams[n-1] = tmp;
	}

	printf("YES\n%d\n", ans); 
	for (int i = n - 1 ; i >= 0; i--) {
		for (int j = 0; j < res[i].size() ; j++) 
			printf("%d %d\n", res[i][j].first, res[i][j].second);

	}
}