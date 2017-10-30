#include <bits/stdc++.h>
using namespace std;

const int MAX = 2010;

struct Node {
	int t, d, p, i;

	Node(int t = 0, int d = 0, int p = 0, int i = 0) : t(t), d(d), p(p), i(i) {}

	bool operator<(const Node& other) const {
		return d < other.d;
	}
};

int f[110][MAX];
vector<int> trace[110][MAX];
Node a[110];
int n;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int t, d, p, i = 1; i <= n; i++) {
		cin >> t >> d >> p;
		a[i] = Node(t, d, p, i);
	}

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < MAX; j++) {
			f[i][j] = f[i-1][j];
			trace[i][j] = trace[i-1][j];
			if (j < a[i].t) {
				continue;
			}
			if (j < a[i].d && f[i][j] < f[i-1][j - a[i].t] + a[i].p) {
				f[i][j] = f[i-1][j - a[i].t] + a[i].p;
				trace[i][j] = trace[i-1][j - a[i].t];
				trace[i][j].push_back(a[i].i);
			}
		}
	}
	int res = 0;
	for (int i = 1; i < MAX; i++) {
		if (f[n][res] < f[n][i]) {
			res = i;
		}
	}
	cout << f[n][res] << "\n";
	cout << trace[n][res].size() << "\n";
	for (auto& item: trace[n][res]) {
		cout << item << " ";
	}

	return 0;
}