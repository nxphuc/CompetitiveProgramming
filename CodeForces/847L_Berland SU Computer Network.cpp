#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;

int n;
vector<unordered_set<int>> adj[MAX];
int vis[MAX];
int cnt[MAX];
vector<pair<int,int>> edges;

void input() {
	string s;

	cin >> n;
	for (int cur, i = 1; i <= n; i++) {
		cnt[i] = 1;
		cin >> s;
		unordered_set<int> subtree;
		cur = 0;
		for (char& ch: s) {
			if (ch == '-') {
				subtree.insert(cur);
				adj[i].push_back(subtree);
				subtree.clear();
				cur = 0;
			}
			else {
				if (ch == ',') {
					subtree.insert(cur);
					cur = 0;
				}
				else {
					if (ch == ':') {
						cur = 0;
					}
					else {
						cur = cur * 10 + ch - '0';
					}
				}
			}
		}
		subtree.insert(cur);
		adj[i].push_back(subtree);
		for (auto& sub: adj[i]) {
			if (sub.find(1) == sub.end()) {
				cnt[i] += sub.size();
			}
		}
	}
}

void Exit() {
	cout << "-1";
	exit(0);
}

unordered_set<int> dfs(int u) {
	unordered_set<int> ret;
	if (vis[u]) {
		Exit();
	}
	vis[u] = 1;
	ret.insert(u);
	for (auto& sub: adj[u]) {
		if (sub.find(1) == sub.end()) {
			int next_child = *sub.begin();
			for (auto& child: sub) {
				if (cnt[next_child] < cnt[child]) {
					next_child = child;
				}
			}
			edges.push_back(make_pair(u, next_child));
			unordered_set<int> tmp = dfs(next_child);
			if (tmp != sub) {
				Exit();
			}
			ret.insert(tmp.begin(), tmp.end());
		}
	}
	return ret;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	input();
	dfs(1);
	cout << edges.size() << "\n";
	for (auto& e: edges) {
		cout << e.first << " " << e.second << "\n";
	}

	return 0;
}