#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10;

vector<int> adj[MAX];
int visited[MAX];
int t, n, m, u, v;

int dfs(int u){
	stack<pair<int,int>> st;
	int i;

	st.push(make_pair(u, 0));
	visited[u] = 1;
	while (!st.empty()){
		u = st.top().first;
		for (i = st.top().second; i < adj[u].size(); i++){
			if (!visited[adj[u][i]]){
				visited[adj[u][i]] = 1;
				st.top().second = i+1;
				st.push(make_pair(adj[u][i], 0));
				break;
			}
			else
				if (visited[adj[u][i]] == 1)
					return 1;
		}
		if (i == adj[u].size()){
			visited[u] = 2;
			st.pop();
		}
	}
	return 0;
}

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			adj[i].clear();
			visited[i] = false;
		}
		for (int i = 0; i < m; i++){
			cin >> u >> v;
			adj[u].push_back(v);
		}

		int cycle = 0;
		for (int i = 1; i <= n; i++)
			if (!visited[i])
				cycle |= dfs(i);
		cout << (cycle ? "SIM\n" : "NAO\n");
	}
	return 0;
}