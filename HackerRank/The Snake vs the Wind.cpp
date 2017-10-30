#include <bits/stdc++.h>
using namespace std;

const int MAX = 70;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int id[4][4] = {{2, 1, 3, 0},
				{0, 1, 3, 2},
				{3, 0, 2, 1},
				{1, 0, 2, 3}
				};
int n, cnt;
int a[MAX][MAX];
string s;
int x, y;
map<string, int> dir;

int isValid(const int& x, const int& y) {
	return 0 <= x && x < n && 0 <= y && y < n && a[x][y] == 0;
}

pair<int,int> getBest(const int& x, const int& y, const string& s) {
	int j = dir[s];
	for (int i = 0; i < 4; i++) {
		if (isValid(x + dx[id[j][i]], y + dy[id[j][i]])) {
			return make_pair(x + dx[id[j][i]], y + dy[id[j][i]]);
		}
	}
	return make_pair(-1, -1);
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	dir["s"] = 0;
	dir["n"] = 1;
	dir["e"] = 2;
	dir["w"] = 3;

	cin >> n;
	cin >> s;
	cin >> x >> y;
	a[x][y] = cnt = 1;
	while (cnt < n*n) {
		pair<int,int> nxt = getBest(x, y, s);
		x = nxt.first;
		y = nxt.second;
		a[x][y] = ++cnt;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}