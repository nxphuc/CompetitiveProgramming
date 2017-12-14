#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> parent;

int findSet(int u) {
	return parent[u] = parent[u] == u ? u : findSet(parent[u]);
}

ll mst(const vector<int>& r, const vector<int>& b) {
	int n = r.size();
	parent.clear();
	for (int i = 0; i < n; i++) {
		parent.push_back(i);
	}
	vector<pair<int, pair<int,int>>> edges;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			edges.push_back(make_pair(min(r[i]^b[j], b[i]^r[j]), make_pair(i, j)));
		}
	}
	sort(edges.begin(), edges.end());
	ll res = 0;
	for (auto edge : edges) {
		int u = edge.second.first;
		int v = edge.second.second;
		u = findSet(u);
		v = findSet(v);
		if (u != v) {
			res += edge.first;
			parent[v] = u;
		}
	}
	return res;
}

int main() {
	freopen("B-large-practice.in", "rt", stdin);
	freopen("B-large-practice.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int t, n;
	vector<int> r, b;

	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		cin >> n;

		r.resize(n);
		b.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> r[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		
		cout << "Case #" << cs << ": " << mst(r, b) << "\n";
	}

	return 0;
}