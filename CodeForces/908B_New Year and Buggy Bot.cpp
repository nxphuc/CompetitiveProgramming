#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int d[4] = {0, 1, 2, 3};
string a[55];
string p;
int n, m;
pair<int, int> s, t;

int isValid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && a[x][y] != '#';
}

int check() {
	int x = s.first;
	int y = s.second;
	// cout << "# " << x << " " << y << "\n";
	for (char dir : p) {
		// cout << "@ " <<(int)(dir - '0') << " " << d[dir - '0'] << "\n";
		x += dx[d[dir - '0']];
		y += dy[d[dir - '0']];
		if (!isValid(x, y)) {
			// cout << "\n";
			// cout << x << " " << y << "\n";
			return 0;
		}
		if (a[x][y] == 'E') {
			return 1;
		}
	}
	return 0;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'S') {
				s = make_pair(i, j);
			}
			if (a[i][j] == 'E') {
				t = make_pair(i, j);
			}
		}
	}
	cin >> p;
	int cnt = 0;
	do {
		cnt += check();
	} while (next_permutation(d, d+4));
	cout << cnt;
	
	return 0;
}