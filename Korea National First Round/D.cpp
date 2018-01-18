#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

vector<int> adj[MAX];
vector<int> path;
int des_dir[MAX];
int n, s, t;

void dfs(int u, int p) {
	if (u == t) {
		des_dir[u] = u;
		return;
	}
	for (auto& v: adj[u]) {
		if (v == p) {
			continue;
		}
		dfs(v, u);
		if (des_dir[v] != 0) {
			des_dir[u] = v;
			return;
		}
	}
	return;
}

void makePath(int u, int p, int flag) {
	if (u == t) {
		for (auto& v: adj[u]) {
			if (v != p) {
				makePath(v, u, 1);
			}
		}
		path.push_back(u);
		return;
	}
	if (flag) {
		path.push_back(u);
	}
	for (auto& v: adj[u]) {
		if (v == p || des_dir[u] == v) {
			continue;
		}
		makePath(v, u, !flag);
	}
	if (!flag) {
		path.push_back(u);
	}
	if (des_dir[u]) {
		makePath(des_dir[u], u, 1);
	}
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int u, v, i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> s >> t;
	dfs(s, 0);
	makePath(s, 0, 1);
	for (auto& p : path)
		cout << p << "\n";

	return 0;
}