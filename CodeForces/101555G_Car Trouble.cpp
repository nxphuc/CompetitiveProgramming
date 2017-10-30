#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;

vector<int> graph[MAX], rev_graph[MAX];
int vis[MAX];
int id[MAX];
int n;

void dfs(vector<int> graph[], const int u) {
	for (const int& v : graph[u]) {
		if (!vis[v]) {
			vis[v] = 1;
			dfs(graph, v);
		}
	}
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int m, u, v, i = 0; i < n; i++) {
		cin >> u;
		id[i] = u;
		cin >> m;
		while (m--) {
			cin >> v;
			graph[u].push_back(v);
			rev_graph[v].push_back(u);
		}
	}
	int flag = 0;
	vis[0] = 1;
	dfs(rev_graph, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[id[i]]) {
			cout << "TRAPPED " << id[i] << "\n";
			flag = 1;
		}
	}
	memset(vis, 0, sizeof(vis));
	vis[0] = 1;
	dfs(graph, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[id[i]]) {
			cout << "UNREACHABLE " << id[i] << "\n";
			flag = 1;
		}
	}
	if (!flag) {
		cout << "NO PROBLEMS";
	}

	return 0;
}