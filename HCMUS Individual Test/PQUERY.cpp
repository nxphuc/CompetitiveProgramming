#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
const int INF = 1e9;

int n;
int a[MAX];
int bit[MAX];
int itMax[MAX * 4], lazMax[MAX];
int itMin[MAX * 4], lazMin[MAX];

void buildTree(int i, int l, int r) {
	if (l > r) {
		return;
	}

	if (l == r) {
		lazMin[i] = lazMax[i] = 0;
		itMin[i] = itMax[i] = a[l];
		return;
	}
	int md = (l + r) >> 1;
	buildTree(i << 1, l, md);
	buildTree(i << 1 | 1, md + 1, r);
	itMin[i] = min(itMin[i << 1], itMin[i << 1 | 1]);
	itMax[i] = max(itMax[i << 1], itMax[i << 1 | 1]);
}

void lazyUpdate(int i) {
	if (lazMin[i]) {
		lazMin[i << 1] += lazMin[i];
		lazMin[i << 1 | 1] += lazMin[i];
		itMin[i << 1] += lazMin[i];
		itMin[i << 1 | 1] += lazMin[i];
		lazMin[i] = 0;
	}
	if (lazMax[i]) {
		lazMax[i << 1] += lazMax[i];
		lazMax[i << 1 | 1] += lazMax[i];
		itMax[i << 1] += lazMax[i];
		itMax[i << 1 | 1] += lazMax[i];
		lazMax[i] = 0;
	}
}

void itUpdate(int i, int l, int r, int lft, int rht, int val) {
	if (l > r || l > rht || r < lft) {
		return;
	}
	if (lft <= l && r <= rht) {
		lazMin[i] += val;
		itMin[i] += val;
		lazMax[i] += val;
		itMax[i] += val;
		return;
	}
	lazyUpdate(i);
	int md = (l + r) >> 1;
	itUpdate(i << 1, l, md, lft, rht, val);
	itUpdate(i << 1 | 1, md + 1, r, lft, rht, val);
	itMin[i] = min(itMin[i << 1], itMin[i << 1 | 1]);
	itMax[i] = max(itMax[i << 1], itMax[i << 1 | 1]);
}

int itQueryMin(int i, int l, int r, int lft, int rht, int val) {
	if (l > r || l > rht || r < lft) {
		return -1;
	}
	if (lft <= l && r <= rht) {
		if (itMin[i] >= val) {
			return -1;
		}
		if (l == r) {
			return l;
		}
		lazyUpdate(i);
		int md = (l + r) >> 1;
		if (itMin[i << 1] < val) {
			return itQueryMin(i << 1, l, md, lft, rht, val);
		}
		else {
			return itQueryMin(i << 1 | 1, md + 1, r, lft, rht, val);
		}
	}

	lazyUpdate(i);
	int md = (l + r) >> 1;
	int tmp = itQueryMin(i << 1, l, md, lft, rht, val);
	return tmp != -1 ? tmp : itQueryMin(i << 1 | 1, md + 1, r, lft, rht, val);
}

int itQueryMax(int i, int l, int r, int lft, int rht, int val) {
	if (l > r || l > rht || r < lft) {
		return -1;
	}
	if (lft <= l && r <= rht) {
		if (itMax[i] < val) {
			return -1;
		}
		if (l == r) {
			return itMax[i] == val ? l : -1;
		}
		lazyUpdate(i);
		int md = (l + r) >> 1;
		int tmp = itQueryMax(i << 1 | 1, md + 1, r, lft, rht, val);
		return tmp != -1 ? tmp : itQueryMax(i << 1, l, md, lft, rht, val);
	}

	lazyUpdate(i);
	int md = (l + r) >> 1;
	int tmp = itQueryMax(i << 1 | 1, md + 1, r, lft, rht, val);
	return tmp != -1 ? tmp : itQueryMax(i << 1, l, md, lft, rht, val);
}

void bitUpdate(int id, int val) {
	while (id < MAX) {
		bit[id] += val;
		id += id & -id;
	}
}

int bitGet(int id) {
	int ret = 0;
	while (id) {
		ret += bit[id];
		id -= id & -id;
	}
	return ret;
}

int main() {
	freopen("PQUERY.INP", "rt", stdin);
	freopen("PQUERY.OUT", "wt", stdout);
	ios::sync_with_stdio(false);

	string s, t;
	cin >> s;
	n = s.length();
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + (s[i] == '(' ? 1 : -1);
		bitUpdate(i, s[i] == '(' ? 1 : -1);
	}
	buildTree(1, 1, n);
	int q, id, val, tmp;
	cin >> q;
	while (q--) {
		cin >> t >> id;
		if (t == "Q") {
			val = bitGet(id - 1);
			tmp = itQueryMin(1, 1, n, id, n, val);
			tmp = tmp == -1 ? n + 1 : tmp;
			tmp = itQueryMax(1, 1, n, id, tmp - 1, val);
			cout << (tmp == -1 ? 0 : tmp - id + 1) << "\n";
		}
		else {
			if (s[id] == ')') {
				s[id] = '(';
				bitUpdate(id, 2);
				itUpdate(1, 1, n, id, n, 2);
			}
			else {
				s[id] = ')';
				bitUpdate(id, -2);
				itUpdate(1, 1, n, id, n, -2);
			}
		}
	}

	return 0;
}