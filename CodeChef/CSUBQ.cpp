#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 5e5 + 10;
const int INF = 2e9;

ll bit[MAX];
ll sub_bit[MAX];
int a[MAX];
map<int, int> low_segments, high_segments;
int n, L, R;

inline ll numWays(ll n) {
	return n * (n + 1LL) / 2LL;
}

void setBit(ll f[], int pos, ll val) {
	while (pos <= n) {
		f[pos] += val;
		pos += pos & -pos;
	}
}

ll getBit(ll f[], int pos) {
	ll res = 0;
	while (pos) {
		res += f[pos];
		pos -= pos & -pos;
	}
	return res;
}

void removePoint(ll f[], map<int, int>& segments, int pos) {
	auto it = segments.lower_bound(pos);

	if (it == segments.end() || it->first != pos) {
		it--;
	}

	int lft = it->first;
	int rht = it->second;
	int len = rht - lft + 1;

	segments.erase(it);
	setBit(f, lft, -numWays(len));
	if (pos != lft) {
		segments[lft] = pos - 1;
		setBit(f, lft, numWays(pos - lft));
	}
	if (pos != rht) {
		segments[pos + 1] = rht;
		setBit(f, pos + 1, numWays(rht - pos));
	}
}

void addPoint(ll f[], map<int, int>& segments, int pos, int lim) {
	int lft = pos;
	int rht = pos;
	if (pos > 1 && a[pos - 1] < lim) {
		auto it = segments.lower_bound(pos);
		it--;
		lft = it->first;
		setBit(f, lft, -numWays(pos - lft));
		segments.erase(it);
	}
	if (pos < n && a[pos + 1] < lim) {
		auto it = segments.lower_bound(pos + 1);
		rht = it->second;
		setBit(f, pos + 1, -numWays(rht - pos));
		segments.erase(it);
	}
	setBit(f, lft, numWays(rht - lft + 1));
	segments[lft] = rht;
}

void update(int p, int x) {
	if (a[p] < L && x < L) {
		return;
	}
	if (a[p] > R && x > R) {
		return;
	}
	if (L <= a[p] && a[p] <= R && L <= x && x <= R) {
		return;
	}
	if (a[p] < L) {
		removePoint(sub_bit, low_segments, p);
	}
	if (a[p] > R) {
		addPoint(bit, high_segments, p, R + 1);
	}
	if (x < L) {
		addPoint(sub_bit, low_segments, p, L);
	}
	if (x > R) {
		removePoint(bit, high_segments, p);
	}
	a[p] = x;
}

ll getSumSegment(ll f[], const map<int, int>& segments, int l, int r) {
	int lft;
	int rht;
	ll res = getBit(f, r) - getBit(f, l - 1);

	if (segments.size() == 0) {
		return 0;
	}

	auto it_lft = segments.lower_bound(l);
	if (it_lft == segments.end() || (it_lft != segments.begin() && it_lft->first > l)) {
		it_lft--;
	}
	if (it_lft->first < l && l <= it_lft->second) {
		res += numWays(it_lft->second - l + 1);
	}
	auto it_rht = segments.lower_bound(r);
	if (it_rht == segments.end() || (it_rht != segments.begin() && it_rht->first > r)) {
		it_rht--;
	}
	if (it_rht->first <= r && r <= it_rht->second) {
		res -= numWays((it_rht->second) - (it_rht->first) + 1);
		res += numWays(r - (it_rht->first) + 1);
	}

	if (it_lft == it_rht && it_rht->first <= l && r <= it_rht->second) {
		res = numWays(r - l + 1);
	}
	return res;
}

ll query(int l, int r) {
	return getSumSegment(bit, high_segments, l, r) - getSumSegment(sub_bit, low_segments, l, r);
}

int main() {
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int q, type, u, v;

	cin >> n >> q >> L >> R;
	high_segments[1] = n;
	low_segments[1] = n;
	setBit(bit, 1, numWays(n));
	setBit(sub_bit, 1, numWays(n));
	while (q--) {
		cin >> type >> u >> v;
		if (type == 1) {
			update(u, v);
		}
		else {
			cout << query(u, v) << "\n";
		}
	}

	return 0;
}