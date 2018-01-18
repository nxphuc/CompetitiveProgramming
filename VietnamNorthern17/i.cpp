#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int INF = 1e9;
typedef long long ll;

int test, n;

int a[MAX];
int vis[MAX];
vector<int> b;

void dfs(int u) {
	if (!a[u]) {
		return;
	}
	for (const int& v : b) {
		if (!vis[v]) {
			vis[v] = 1;
			dfs(v);
		}
	}
}

int main() {
	// freopen("test", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> test;

	while (test--) {
		cin >> n;
		int cnt = 0;
		memset(vis, 0, sizeof(vis));
		b.clear();
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int x, i = 0; i < n; i++) {
			cin >> x;
			if (x) {
				b.push_back(i);
			}
		}
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				cnt++;
				dfs(i);
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}