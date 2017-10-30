#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int a[MAX];
vector<int> adj[MAX];
int pos[MAX], neg;
int n;
vector<int> best_path;
int best;

void dfs1(int u = 1, int p = -1) {
	pos[u] = max(0, a[u]);
	neg[u] = min(0, a[u]);
	for (const auto& v: adj[u]) {
		if (v != p) {
			dfs1(v, u);
			pos[u] += max(0, pos[v]);
			neg[u] += min(0, neg[v]);
		}
	}
}

void dfs2(int u, int p, int prev_pos, int prev_neg) {
	prev_pos = max(0, max(a[u], prev_pos + a[u]));
	prev_neg
	int pos_diff = 0, neg_diff = 0;
	for (const auto& v: adj[u]) {
		if (v != p) {
			if (diff[v] < 0) {
				neg_diff += diff[v];
			}
			else {
				pos_diff += diff[v];
			}
		}
	}
	best = max(best, max(abs(prev_diff + pos_diff), abs(prev_diff + neg_diff)));
	for (const auto& v: adj[u]) {
		if (v != p) {
			dfs2(v, u, prev_diff + pos_diff + neg_diff - diff[v]);
		}
	}
}

void dfs3(int u, int p) {
	best_path.push_back(u);
	for (const auto& v: adj[u]) {
		if (v != p) {
			dfs3(v, u);
		}
	}
}

bool traceResult(int u, int p, int prev_diff) {
	prev_diff += a[u];
	int pos_diff = 0, neg_diff = 0;
	for (const auto& v: adj[u]) {
		if (v != p && diff[v]) {
			if (diff[v] < 0) {
				neg_diff += diff[v];
			}
			else {
				pos_diff += diff[v];
			}
		}
	}
	if (abs(prev_diff + pos_diff) == best) {
		best_path.push_back(u);
		for (const auto& v: adj[u]) {
			if (v == p || diff[v] > 0) {
				dfs3(v, u);
			}
		}
		return true;
	}
	if (abs(prev_diff + neg_diff) == best) {
		best_path.push_back(u);
		for (const auto& v: adj[u]) {
			if (v == p || diff[v] < 0) {
				dfs3(v, u);
			}
		}
		return true;
	}
	for (const auto& v: adj[u]) {
		if (v != p && traceResult(v, u, prev_diff + pos_diff + neg_diff - diff[v])) {
			return true;
		}
	}
	return false;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = 2*a[i] - 1;
	}
	for (int x, y, i = 1; i < n; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs1();
	best = 1;
	dfs2(1, -1, 0);
	traceResult(1, -1, 0);
	cout << best << "\n";
	cout << best_path.size() << "\n";
	for (auto& vertex: best_path) {
		cout << vertex << " ";
	}

	return 0;
}