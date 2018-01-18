#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// #include <climits>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;
const int MOD = 1e9;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

struct Node {
	vector<int> cnt;
	int lazy;

	Node() {
		cnt = vector<int>(40);
		lazy = 0;
	}
};

Node node[4 * MAX];
int a[MAX];
int n, m, u, v, t;

vector<int> getValue(int id) {
	vector<int> res(40, 0);
	for (int i = 39; i > 0; i--) {
		if (i > node[id].lazy) {
			res[i] = node[id].cnt[i - node[id].lazy];
		}
		else {
			res[i] = 0;
		}
	}
	return res;
}

void updateNode(int id) {
	for (int i = 39; i > 0; i--) {
		if (i > node[id].lazy) {
			node[id].cnt[i] = node[id].cnt[i - node[id].lazy];
		}
		else {
			node[id].cnt[i] = 0;
		}
	}
}

void down(int id) {
	node[id * 2].lazy += node[id].lazy;
	node[id * 2 + 1].lazy += node[id].lazy;
	// updateNode(id);
	node[id].lazy = 0;
}

void buildTree(int id, int l, int r) {
	if (l == r) {
		node[id].lazy = 0;
		if (a[l] < 40) {
			node[id].cnt[a[l]] = 1;
		}
		return;
	}
	int m = (l + r) / 2;
	buildTree(id*2, l, m);
	buildTree(id*2+1, m+1, r);
	for (int i = 0; i < 40; i++) {
		node[id].cnt[i] = node[id*2].cnt[i] + node[id*2+1].cnt[i];
	}
	node[id].lazy = 0;
}

void updateRange(int id, int s, int e, int l, int r) {
	if (l > r || r < s || e < l) {
		return;
	}
	if (l == r) {
		fill(node[id].cnt.begin(), node[id].cnt.end(), 0);
		a[l] += node[id].lazy + 1;
		if (a[l] < 40) {
			node[id].cnt[a[l]] = 1;
		}
		node[id].lazy = 0;
		return;
	}
	if (s <= l && r <= e) {
		node[id].lazy++;
		// updateNode(id);
		/*for (int i = 39; i > 0; i--) {
		 	node[id].cnt[i] = node[id].cnt[i - 1];
		}*/
		return;
	}
	updateNode(id);
	down(id);
	int m = (l + r) / 2;
	updateRange(id * 2, s, e, l, m);
	updateRange(id * 2 + 1, s, e, m + 1, r);
	vector<int> lft = getValue(2*id);
	vector<int> rht = getValue(2*id+1);
	for (int i = 1; i < 40; i++) {
		node[id].cnt[i] = lft[i] + rht[i];
	}
}

void updatePoint(int id, int l, int r, int pos, int val) {
	if (l == r) {
		fill(node[id].cnt.begin(), node[id].cnt.end(), 0);
		a[l] = val;
		if (a[l] < 40) {
			node[id].cnt[a[l]] = 1;
		}
		node[id].lazy = 0;
		return;
	}
	updateNode(id);
	down(id);
	int m = (l + r) / 2;
	if (pos <= m) {
		updatePoint(id * 2, l, m, pos, val);
	}
	else {
		updatePoint(id * 2 + 1, m + 1, r, pos, val);
	}
	vector<int> lft = getValue(2*id);
	vector<int> rht = getValue(2*id+1);
	for (int i = 1; i < 40; i++) {
		node[id].cnt[i] = lft[i] + rht[i];
	}
}

vector<int> query(int id, int s, int e, int l, int r) {
	if (l > r || r < s || e < l) {
		return vector<int>(40, 0);
	}
	if (s <= l && r <= e) {
		return getValue(id);
	}

	updateNode(id);
	down(id);
	int m = (l + r) / 2;
	vector<int> lft = query(id * 2, s, e, l, m);
	vector<int> rht = query(id * 2 + 1, s, e, m + 1, r);
	vector<int> res(40, 0);
	for (int i = 1; i < 40; i++) {
		res[i] = lft[i] + rht[i];
	}
	return res;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	ll fact[40] = {1};
	for (ll i = 1; i < 40; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	buildTree(1, 1, n);
	while (m--) {
		cin >> t;
		if (t == 1) {
			cin >> u >> v;
			updateRange(1, u, v, 1, n);
			continue;
		}
		if (t == 2) {
			cin >> u >> v;
			vector<int> cnt = query(1, u, v, 1, n);
			ll res = 0;
			for (int i = 1; i < 40; i++) {
				// cout << cnt[i] << " ";
				res = (res + (1LL * cnt[i] * fact[i])) % MOD;
			}
			// cout << "\n";
			cout << res << "\n";
			continue;
		}
		cin >> u >> v;
		updatePoint(1, 1, n, u, v);
	}

	return 0;
}