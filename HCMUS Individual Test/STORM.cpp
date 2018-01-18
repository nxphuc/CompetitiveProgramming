#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1e5 + 10;
const ll INF = 1e17;

vector<pair<int,int>> adj[MAX];
ll len[MAX];

void dfs(int u, int p) {
	for (auto& c: adj[u]) {
		if (c.first != p) {
			len[c.first] = len[u] + c.second;
			dfs(c.first, u);
		}
	}
}

int main() {
	freopen("STORM.INP", "rt", stdin);
	freopen("STORM.OUT", "wt", stdout);
	ios::sync_with_stdio(false);

	int n, m;
	vector<int> lst;
	cin >> n >> m;
	for (int u, v, c, i = 1; i < n; i++) {
		cin >> u >> v >> c;
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}
	for (int x, i = 0; i < m; i++) {
		cin >> x;
		lst.push_back(x);
	}
	dfs(lst[0], 0);
	ll max_len = -1;
	int min_id = MAX;
	for (auto i : lst) {
		if (max_len < len[i] || (max_len == len[i] && min_id > i)) {
			max_len = len[i];
			min_id = i;
		}
	}
	len[min_id] = 0;
	dfs(min_id, 0);
	max_len = -1;
	int min_id2 = MAX;
	for (auto i : lst) {
		if (max_len < len[i] || (max_len == len[i] && min_id2 > i)) {
			max_len = len[i];
			min_id2 = i;
		}
	}
	cout << min(min_id, min_id2);

	return 0;
}