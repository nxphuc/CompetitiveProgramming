#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	map<pair<string,string>, int> map_count;
	vector<int> cost_list;
	int n, a, b, k, f;
	string s, t, prv = "";

	cin >> n >> a >> b >> k >> f;
	for (int cost, i = 0; i < n; i++) {
		cin >> s >> t;
		if (s == prv) {
			cost = b;
		}
		else {
			cost = a;
		}
		prv = t;
		if (s > t) {
			swap(s, t);
		}
		map_count[make_pair(s, t)] += cost;
	}
	for (auto& pkv: map_count) {
		cost_list.push_back(pkv.second);
	}
	sort(cost_list.begin(), cost_list.end(), greater<int>());
	int res = 0;
	for (int i = 0; i < cost_list.size(); i++) {
		if (i < k && cost_list[i] > f) {
			res += f;
		}	
		else {
			res += cost_list[i];
		}
	}
	cout << res;

	return 0;
}