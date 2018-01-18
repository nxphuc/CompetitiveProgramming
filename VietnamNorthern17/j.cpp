#include <bits/stdc++.h> 

using namespace std;  

const int N = 300;
const int MAX = 1e5 + 10;
const int INF = 1e9 + 10;
typedef long long ll;

int d[N], vis[N];
int n, m;
vector<pair<int, int> > edge;
int a[N][N];

int dijktra(int s, int t)
{
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
		vis[i] = 0;
	}
	d[s] = 0;
	while (1) {
		int x = INF, pos = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && d[i] < x) {
				x = d[i];
				pos = i;
			}
		}
		if (pos == 0) return -1;
		if (pos == t) return d[pos];
		vis[pos] = 1;
		for (int i = 1; i <= n; i++) 
			if (!vis[i] && a[pos][i] && d[i] > d[pos] + a[pos][i]) {
				d[i] = d[pos] + a[pos][i];
			}
	}
}

int deg[N];

int main () { 

	scanf("%d %d", &n, &m);  

	if (n == 2) { 
		printf("-1.000000");  
		return  0;  
	}
	for (int i = 0; i < m; i++) { 
		int x, y, val; 
		scanf("%d %d %d", &x, &y, &val);  
		a[x][y] = val;
		deg[x]++;
		deg[y]++;
		a[y][x] = val; 
		edge.push_back({x, y});
	}
	bool ok = false;
	for (int i = 1; i <= n; i++) {
		if (deg[i] > 1) ok = true;
	}
	if (!ok) {
		printf("-1.000000");   
		return  0;  
	}
	double ans = 1.0;
	for (auto tmp : edge) {
		int x = tmp.first;
		int y = tmp.second;
		int old = a[x][y];
		a[x][y] = a[y][x] = 0;
		int ret = dijktra(x, y);
		if (ret >= 0)
			ans = max(ans, 1.0 * ret / old);
		a[x][y] = a[y][x] = old;
	}

	printf("%.6f", ans);
}