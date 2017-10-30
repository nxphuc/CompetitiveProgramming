#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n, x;
	string s;
	map<int,int> lst;

	cin >> t;
	while (t--) {
		cin >> n;
		lst.clear();
		for (int i = 0; i < n; i++) {
			cin >> s >> x;
			lst[x]++;
		}
		int res = lst.begin()->first;
		int cnt = lst.begin()->second;
		for (const auto& kvp : lst) {
			if (kvp.second > cnt) {
				res = kvp.first;
				cnt = kvp.second;
			}
		}
		cout << res << "\n";
	}
	return 0;
}