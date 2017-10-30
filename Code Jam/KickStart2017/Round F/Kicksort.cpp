#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10;

int a[MAX];
int bit[MAX];
int t, n;

void update(int id, int x) {
	while (id < MAX) {
		bit[id] += x;
		id += id & -id;
	}
}

int query(int id) {
	int ret = 0;
	while (id) {
		ret += bit[id];
		id -= id & -id;
	}
	return ret;
}

int doit() {
	int lft = 1, rht = n;
	int cnt_lft, cnt_rht;
	for (int remain = n; remain > 1; remain--) {
		cnt_lft = query(a[lft] - 1);
		cnt_rht = query(a[rht] - 1);
		if ((remain - 1) / 2 == cnt_lft) {
			update(a[lft], -1);
			lft++;
			continue;
		}
		if ((remain - 1) / 2 == cnt_rht) {
			update(a[rht], -1);
			rht--;
			continue;
		}
		return 0;
	}
	return 1;
}

int main() {
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		memset(bit, 0, sizeof(bit));
		cin >> n;
		for (int x, i = 0; i < n; i++) {
			cin >> x;
			a[x] = i + 1;
			update(x, 1);
		}
		cout << "Case #" << cs << ": " << (doit() ? "YES\n" : "NO\n");
	}


	return 0;
}