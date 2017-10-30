#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10;

vector<int> adj[MAX];
int visited[MAX];
int t, n, m, u, v;

int dfs(int u){
	visited[u] = 1;

	int v;
	for (int i = 0; i < adj[u].size(); i++){
		v = adj[u][i];
		if (visited[v] == 1){
			return 1;
		}
		else
			if (visited[v] == 0){
				if (dfs(v))
					return 1;
			}
	}

	visited[u] = 2;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			adj[i].clear();
			visited[i] = 0;
		}
		for (int i = 0; i < m; i++){
			cin >> u >> v;
			adj[u].push_back(v);
		}

		int cycle = 0;
		for (int i = 1; i <= n; i++)
			if (!visited[i]){
				cycle = dfs(i);
				if (cycle) break;
			}
		cout << (cycle ? "SIM\n" : "NAO\n");
	}
	return 0;
}