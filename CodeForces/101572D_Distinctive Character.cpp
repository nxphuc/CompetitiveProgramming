#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, k;
	string s;
	cin >> n >> k;

	vector<int> d(1 << (k + 1), -1);
	queue<int> q;
	for (int x, i = 0; i < n; i++) {
		cin >> s;
		x = 0;
		for (const char& ch : s) {
			x = x << 1 | (ch - '0'); 
		}
		d[x] = 0;
		q.push(x);
	}

	int ans = 0;
	int u, v;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 0; i < k; i++) {
			v = u ^ (1 << i);
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
				ans = v;
			}
		}
	}
	for (int i = k-1; i >= 0; i--) {
		cout << ((ans >> i) & 1);
	}

	return 0;
}