#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 5e5 + 2;
const int INF = 1e9;

vector<int> adj[MAX];
int cnt[MAX];
char mark[MAX];
int n, m;
ll res;

void dfs1(int u, int p){
	for (int v : adj[u])
		if (v != p){
			dfs1(v, u);
			cnt[u] += cnt[v];
		}
}

void dfs2(int u, int p, ll prv, int cntPrv){
	if (mark[u])
		res = min(res, prv);
	for (int v : adj[u])
		if (v != p)
			dfs2(v, u, prv + cntPrv + cnt[u] - cnt[v], cntPrv + cnt[u] - cnt[v]);
}

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int u, v, i = 1; i < n; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int u, i = 0; i < m; i++){
		cin >> u;
		mark[u] = cnt[u] = 1;
	}
	dfs1(1, 0);
	if (mark[1])
		res = 0;
	else{
   		res = 1LL*n*n;
		dfs2(1, 0, 0, 0);
	}
	cout << res;

	return 0;
}