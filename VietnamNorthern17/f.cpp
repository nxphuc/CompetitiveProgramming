#include <bits/stdc++.h> 

using namespace std;  

const int N = 300;
const int MAX = 1e5 + 10;
const int INF = 1e9 + 10;
typedef long long ll;

int n,m;
list<int> a[N];
bool used[N], f[2][N][N];

void dfs(int x, int &odd, int &even) {
	++odd;
	used[x] = 1;
	list<int>::iterator it;
	for(it = a[x].begin(); it != a[x].end(); it++) {
		int y = *it;
		++even;
		if (used[y]) continue;
		dfs(y, odd, even);
	}
}

void solve(int &odd, int &odd2, int &even) {
	odd = even = odd2 = 0;
	memset(used + 1, 0, sizeof(used));
	for (int i = 1, tmp_n, tmp_m; i <= n; ++i)
	if (!used[i]) {
		tmp_n = tmp_m = 0;
		dfs(i, tmp_n, tmp_m);
		tmp_m >>= 1;
		odd++;
		if (tmp_n & 1) {
			odd2++;
		}
		even += tmp_n * (tmp_n - 1) / 2 - tmp_m;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	for (int i = 0; i <= 2; i++) {
		f[0][2][i] = f[1][2][i] = 1;
	}
	for (int i = 0; i <= 3; i++) {
		f[0][3][i] = 0;
		f[1][3][i] = 1;
	}
	for (int i = 4; i < N; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= i; k++) {
				f[j][i][k] = 0;
				if (i - k >= 2)
					f[j][i][k] |= !f[1 - j][i - 1][k];
				if (k >= 1 && i - k >= 1)
					f[j][i][k] |= !f[1 - j][i - 1][k];
				if (k >= 2) 
					f[j][i][k] |= !f[j][i - 1][k - 2];
			}
		}
	}
	int test;
	cin >> test;
	while (test--) {
		cin >> n >> m;
		for (int i= 1; i <= n; i++) {
			a[i].clear();
		}
		for (int i= 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		int x, y, z;
		solve(x, y, z);
		cout << f[x % 2][y][z] << endl;
	}
}