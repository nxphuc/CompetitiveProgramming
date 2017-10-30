#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

vector<int> a[MAX];
int dist[2][MAX];
int par[MAX];
int n, x, u, v;

int dfs(int u, int p){
	int ret = 0;
	dist[0][u] = dist[0][p] + 1;
	par[u] = p;
	for (int v: a[u])
		if (v != p)
			ret = max(ret, dfs(v, u) + 1);
	return dist[1][u] = ret;
}

int calcDist(int u, int v){
	return dist[0][v] - dist[0][u];
}

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> n >> x;
	for (int i = 1; i < n; i++){
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1, 0);
	int res = 2*(calcDist(1, x) + dist[1][x]);
	for (int i = 1; ; i++){
		x = par[x];
		if (calcDist(1, x) > i)
			res = max(res, 2*(calcDist(1, x) + dist[1][x]));
		else
			break;
	}
	cout << res;

	return 0;
}