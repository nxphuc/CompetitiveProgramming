#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1000001;

map<int,int> cnt[MAX];
int cnt2[MAX];

int main() {
	freopen("CONTAINER.INP", "rt", stdin);
	freopen("CONTAINER.OUT", "wt", stdout);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int u, v, i = 0; i < n; i++) {
		cin >> u >> v;
		if (u > v) swap(u, v);
		cnt2[u]++;
		cnt[u][v]++;
	}
	ll res = 0;
	for (int i = 1; i < MAX; i++) {
		for (auto& p : cnt[i]) {
			if (i == p.first) {
				if (p.second >= 6) {
					res = max(res, 1LL*i*i*i);
				}
			}
			else {
				if (p.second < 2) continue;
				p.second -= 2;
				for (auto& q : cnt[p.first]) {
					if (q.second < 2) continue;
					q.second -= 2;
					if (cnt[i][q.first] > 1) {
						res = max(res, 1LL * i * p.first * q.first);
					}
					q.second += 2;
				}
				p.second += 2;
			}
		}
	}
	cout << res << "\n";

	return 0;
}