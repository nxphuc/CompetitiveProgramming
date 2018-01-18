#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 2e5 + 10;

pair<ll, int> persons[MAX];
ll BIT1[MAX];
int a[MAX];
vector<int> b[MAX];
unordered_map<int, int> convert;
set<int> list_number;
int t, n, m, nc;

void setBIT(ll BIT[], int id, int val) {
	while (id < MAX) {
		BIT[id] += val;
		id += id & -id;
	}
}


ll getBIT(ll BIT[], int id) {
	ll ret = 0;
	while (id) {
		ret += BIT[id];
		id -= id & -id;
	}
	return ret;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	// cin >> t;
	scanf("%d", &t);
	assert(0 < t <= 10);
	while (t--) {
		// cin >> n >> m;
		scanf("%d%d", &n, &m);
		assert(0 < n && n <= m && m <= 200000);

		memset(BIT1, 0, sizeof(BIT1));
		list_number.clear();
		convert.clear();
		for (int i = 0; i < n; i++) {
			b[i].clear();
		}

		for (int i = 0; i < n; i++) {
			persons[i] = make_pair(0, i);
		}
		
		for (int i = 0; i < m; i++) {
			// cin >> a[i];
			scanf("%d", &a[i]);
			assert(0 < a[i] && a[i] <= 1000000000);
			list_number.insert(a[i]);
		}
		nc = 0;
		for (const auto& number : list_number) {
			convert[number] = ++nc;
		}

		for (int x, i = 0; i < m; i++) {
			// cin >> x;
			scanf("%d", &x);
			assert(0 < x <= n);
			x--;
			b[x].push_back(convert[a[i]]);
			persons[x].first += a[i];
		}
		
		sort(persons, persons + n);
		ll res = 0;
		for (int i = 0; i < n; i++) {
			if (b[persons[i].second].size() > 1) {
				for (const auto& val : b[persons[i].second]) {
					res += getBIT(BIT1, val - 1);
				}
			}
			for (const auto& val : b[persons[i].second]) {
				setBIT(BIT1, val, 1);
			}
		}
		printf("%lld\n", res);
		// cout << res - cnt*(cnt - 1)/2 << "\n";
	}

	return 0;
}