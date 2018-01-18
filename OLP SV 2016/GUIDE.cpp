#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int p[20][MAX];
vector<int> a[MAX];
int vis[MAX];
int level[MAX];
int n, k;
int u, v, res;

void dfs(int u, int par){
	vis[u] = 1;
	p[0][u] = par;
	level[u] = level[par] + 1;
	for (int i = 0; i < a[u].size(); i++)
		if (!vis[a[u][i]])
			dfs(a[u][i], u);
}

void makeLCA(){
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			p[i][j] = p[i-1][p[i-1][j]];
}

int getParent(int u, int lv){
	for (int i = 19; i >= 0; i--)
		if (p[i][u] != -1 && level[p[i][u]] >= lv)
			u = p[i][u];
	while (level[u] > lv)
		u = p[0][u];

	return u;
}

int LCA(int u, int v){
	for (int i = 19; i >= 0; i--)
		if (level[p[i][u]] >= level[v])
			u = p[i][u];
	for (int i = 19; i >= 0; i--)
		if (level[p[i][v]] >= level[u])
			v = p[i][v];
	for (int i = 19; i >= 0; i--)
		if (p[i][u] != p[i][v])
			u = p[i][u], v = p[i][v];
	while (u != v)
		u = p[0][u], v = p[0][v];

	return u;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < k; i++){
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i, 0);
	makeLCA();

	cin >> k;
	while (k--){
		cin >> u >> v;
		res = LCA(u, v);
		if (!res){
			cout << -1 << "\n";
		}
		else
			if (res == u){
				cout << getParent(v, level[u] + 1) << "\n";
			}
			else{
				cout << p[0][u] << "\n";
			}
	}

	return 0;
}