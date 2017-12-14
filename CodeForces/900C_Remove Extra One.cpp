#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n;
	set<int> s;
	set<int>::iterator it;
	
	cin >> n;

	vector<int> f(n+1, 0);
	vector<int> g(n+1, 0);
	int record = 0;
	int max_record = -1, min_id = n+1;
	for (int a, i = 0; i < n; i++) {
		cin >> a;
		it = s.upper_bound(a);
		if (it == s.end()) {
			f[a] = 1;
			record++;
		}
		else {
			if (s.upper_bound(*it) == s.end()) {
				g[*it]++;
			}
		}
		s.insert(a);
	}
	for (int i = 1; i <= n; i++) {
		int num = record - f[i] + g[i];
		if (max_record < num) {
			max_record = num;
			min_id = i;
		}
	}
	cout << min_id;

	return 0;
}