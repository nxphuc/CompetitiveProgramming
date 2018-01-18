#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

struct Node {
	int source, dest;

	Node(int s, int d) : source(s), dest(d) {}
	bool operator<(const Node& other) const {
		if (dest != other.dest) {
			return dest < other.dest;
		}
		return source < other.source;
	}
};

int bit[2][MAX];
int t, m, n;

void update(int id, int pos, int val) {
	while (pos <= m) {
		bit[id][pos] = max(bit[id][pos], val);
		pos += pos & -pos;
	}
}

int query(int id, int pos) {
	int res = -1;
	while (pos > 0) {
		res = max(res, bit[id][pos]);
		pos -= pos & -pos;
	}
	return res;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> m >> n;
		vector<int> id(n), s(n);
		memset(bit[0], 0, MAX*sizeof(int));
		memset(bit[1], 0, MAX*sizeof(int));
		for (int i = 0; i < n; i++) {
			char ch;
			cin >> ch;
			id[i] = (ch == 'E' || ch == 'C');
		}
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		vector<Node> trips[2];
		vector<int> f(n+1, -1);
		for (int x, i = 0; i < n; i++) {
			cin >> x;
			if (x >= s[i]) {
				trips[id[i]].push_back(Node(s[i], x));
			}
		}
		sort(trips[0].begin(), trips[0].end());
		sort(trips[1].begin(), trips[1].end());
		// for (Node trip : trips[0]) {
		// 	cout << trip.source << " " << trip.dest << "\n";
		// }
		int i = 0, j = 0;
		int n1 = trips[0].size(), n2 = trips[1].size();
		while (i < n1 && j < n2) {
			if (trips[0][i].source < trips[1][j].source) {
				int mx = max(query(0, trips[0][i].dest),
							query(1, trips[0][i].source));
				update(0, trips[0][i].dest, mx + 1);
				if (f[mx+1] == -1 || f[mx+1] > trips[0][i].dest) {
					f[mx+1] = trips[0][i].dest;
				}
				i++;
			}
			else {
				int mx = max(query(1, trips[1][j].dest),
							query(0, trips[1][j].source));
				update(1, trips[1][j].dest, mx + 1);
				if (f[mx+1] == -1 || f[mx+1] > trips[1][j].dest) {
					f[mx+1] = trips[1][j].dest;
				}
				j++;
			}
		}
		while (i < n1) {
			int mx = max(query(0, trips[0][i].dest),
						query(1, trips[0][i].source));
			update(0, trips[0][i].dest, mx + 1);
			if (f[mx+1] == -1 || f[mx+1] > trips[0][i].dest) {
				f[mx+1] = trips[0][i].dest;
			}
			i++;
		}
		while (j < n2) {
			int mx = max(query(1, trips[1][j].dest),
						query(0, trips[1][j].source));
			update(1, trips[1][j].dest, mx + 1);
			if (f[mx+1] == -1 || f[mx+1] > trips[1][j].dest) {
				f[mx+1] = trips[1][j].dest;
			}
			j++;
		}
		for (int i = 1; i <= n; i++) {
			cout << f[i] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}