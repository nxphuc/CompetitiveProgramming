#include <bits/stdc++.h> 

using namespace std; 

typedef unsigned long long ull;

const double EPS = 0.0000001;
const int MAX = 2e5 + 10;

struct item
{
	int x, y, val;
};

int n, m;
item lst[1000];
string a[1000];
int cnt;

bool check(int x, int y)
{
	if (x < 0 || x >= n) return true;
	if (y < 0 || y >= m) return true;
	if (a[x][y] != '.') return true;
	return false;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void tri(int id, int dir)
{
	if (id == cnt) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << a[i][j];
			cout << endl;
		}
		exit(0);
	}
	int x = lst[id].x;
	int y = lst[id].y;
	int val = lst[id].val;
	int newx, newy;
	if (dir == 0) {
		newy = y;
		int i;
		for (i = 0; i <= val; i++) {
			newx = x - i;
			if (i == 0) {
				tri(id, dir + 1);
				continue;
			}
			if (check(newx, newy)) break;
			a[newx][newy] = '^';
			lst[id].val--;
			tri(id, dir + 1);
		}
		for (int j = 1; j < i; j++) {
			a[x - j][y] = '.';
			lst[id].val++;
		}
	}

	if (dir == 1) {
		newy = y;
		int i;
		for (i = 0; i <= val; i++) {
			newx = x + i;
			if (i == 0) {
				tri(id, dir + 1);
				continue;
			}
			if (check(newx, newy)) break;
			a[newx][newy] = 'v';
			lst[id].val--;
			tri(id, dir + 1);
		}
		for (int j = 1; j < i; j++) {
			a[x + j][y] = '.';
			lst[id].val++;
		}
	}

	if (dir == 2) {
		newx = x;
		int i;
		for (i = 0; i <= val; i++) {
			newy = y - i;
			if (i == 0) {
				tri(id, dir + 1);
				continue;
			}
			if (check(newx, newy)) break;
			a[newx][newy] = '<';
			lst[id].val--;
			tri(id, dir + 1);
		}
		for (int j = 1; j < i; j++) {
			a[x][y - j] = '.';
			lst[id].val++;
		}
	}

	if (dir == 3) {
		newx = x;
		int i;
		for (i = 1; i <= val; i++) {
			newy = y + i;
			if (check(newx, newy)) break;
			a[newx][newy] = '>';
			lst[id].val--;
		}
		if (i > val) {
			bool ok = true;
			bool ok2;
			int nxt_x, nxt_y;
			if (!check(x - 1, y)) {
				ok2 = true;
				newx = x - 1;
				newy = y;
				for (int j = 0; j < 4; j++) {
					if (j == 2) continue;
					nxt_x = newx;
					nxt_y = newy;
					for (int k = 0; ; k++) {
						nxt_x += dx[j];
						nxt_y += dy[j];
						if (0 <= nxt_x && nxt_x < n && 0 <= nxt_y && nxt_y < m) {
							if (a[nxt_x][nxt_y] >= '0' && a[nxt_x][nxt_y] <= '9')
							{
								ok2 = false;
							 	break; 
							}
							if (a[nxt_x][nxt_y] != '.') break;
						} else break;
					}
				}
			}
			if (ok2) ok = false;
			if (!check(x + 1, y)) {
				newx = x + 1;
				newy = y;
				for (int j = 0; j < 4; j++) {
					if (j == 3) continue;
					nxt_x = newx;
					nxt_y = newy;
					for (int k = 0; ; k++) {
						nxt_x += dx[j];
						nxt_y += dy[j];
						if (0 <= nxt_x && nxt_x < n && 0 <= nxt_y && nxt_y < m) {
							if (a[nxt_x][nxt_y] >= '0' && a[nxt_x][nxt_y] <= '9')
							{
								ok2 = false;
							 	break; 
							}
							if (a[nxt_x][nxt_y] != '.') break;
						} else break;
					}
				}
			}
			if (ok2) ok = false;
			if (!check(x, y - 1)) {
				newx = x;
				newy = y - 1;
				for (int j = 0; j < 4; j++) {
					if (j == 0) continue;
					nxt_x = newx;
					nxt_y = newy;
					for (int k = 0; ; k++) {
						nxt_x += dx[j];
						nxt_y += dy[j];
						if (0 <= nxt_x && nxt_x < n && 0 <= nxt_y && nxt_y < m) {
							if (a[nxt_x][nxt_y] >= '0' && a[nxt_x][nxt_y] <= '9')
							{
								ok2 = false;
							 	break; 
							}
							if (a[nxt_x][nxt_y] != '.') break;
						} else break;
					}
				}
			}
			if (ok2) ok = false;
			if (!check(x, y + 1)) {
				newx = x;
				newy = y + 1;
				for (int j = 0; j < 4; j++) {
					if (j == 1) continue;
					nxt_x = newx;
					nxt_y = newy;
					for (int k = 0; ; k++) {
						nxt_x += dx[j];
						nxt_y += dy[j];
						if (0 <= nxt_x && nxt_x < n && 0 <= nxt_y && nxt_y < m) {
							if (a[nxt_x][nxt_y] >= '0' && a[nxt_x][nxt_y] <= '9')
							{
								ok2 = false;
							 	break; 
							}
							if (a[nxt_x][nxt_y] != '.') break;
						} else break;
					}
				}
			}
			if (ok2) ok = false;
			if (ok) tri(id + 1, 0);
		}
		for (int j = 1; j < i; j++) {
			a[x][y + j] = '.';
			lst[id].val++;
		}
	}
}

int main () { 
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] >= '0' && a[i][j] <= '9') {
				lst[cnt].x = i;
				lst[cnt].y = j;
				lst[cnt].val = a[i][j] - '0';
				cnt++;
			}
		}
	}
	tri(0, 0);
	return 0;
}