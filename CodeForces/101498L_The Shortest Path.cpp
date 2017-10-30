#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
	int from, to;
	ll cost;

	Edge(int from = 0, int to = 0, ll cost = 0) : from(from), to(to), cost(cost) {}
};

const ll INF = 2e15;
const int MAX = 5e3 + 10;

ll d[MAX];
Edge e[MAX];
int t, n, m;
ll mn;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			d[i] = 0;
		}
		mn = INF;
		for (int i = 0; i < m; i++) {
			cin >> e[i].from >> e[i].to >> e[i].cost;
			mn = min(mn, e[i].cost);
		}
		int flag;
		for (int i = 0; i < n; i++) {
			flag = 0;
			for (int j = 0; j < m; j++) {
				if (d[e[j].to] > d[e[j].from] + e[j].cost) {
					d[e[j].to] = d[e[j].from] + e[j].cost;
					flag = 1;
				}
			}
			if (!flag) {
				break;
			}
		}
		if (flag) {
			cout << "-inf\n";
		}
		else {
			ll tmp = INF;
			for (int i = 1; i <= n; i++) {
				tmp = min(tmp, d[i]);
			}
			mn = tmp ? min(tmp, mn) : mn;
			cout << mn << "\n";
		}
	}

	return 0;
}