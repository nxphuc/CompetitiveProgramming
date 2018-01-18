#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define pb push_back

const int MAX = 1e6 + 10;
const int N = 1e3 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m, a[N][N], f[N][N];

bool inside(int x, int y)
{
	return (0 <= x && x < n && 0 <= y && y < m);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f[i][j] = a[i][j];
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (inside(x, y))
					f[i][j] = max(f[i][j], a[x][y]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << f[i][j] << " ";
		cout << endl;
	}
	return 0;
}