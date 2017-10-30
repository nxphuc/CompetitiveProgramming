#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int n, m;
vector<int> a[MAX];
int gr[MAX];
int enemy[MAX];

void update(int u, int c) {
	gr[u] = c;
	for (int v : a[u]) {
		if (gr[v] == c) {
			enemy[u]++;
			enemy[v]++;
			if (enemy[v] == 2) {
				for (int k : a[v]) {
					if (gr[k] == gr[v]) {
						enemy[v]--;
						enemy[k]--;
					}
				}
				update(v, 1 - c);
			}
		}
	}
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int u, v, i = 0; i < m; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	memset(gr, -1, sizeof(gr));

	for (int i = 1; i <= n; i++) {
		int cnt[2] = {0};
		for (int j : a[i]) {
			if (gr[j] != -1) {
				cnt[gr[j]]++;
			}
		}
		update(i, cnt[0] > 1 ? 1 : 0);
	}
	vector<vector<int>> res;

	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (gr[i] == 1) {
			flag = 1;
			break;
		}
	}
	cout << flag + 1 << "\n";
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			if (gr[j] == i) {
				cout << j << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}