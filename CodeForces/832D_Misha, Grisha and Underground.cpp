/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 2e5 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int p[21][MAX];
int l[MAX];
int a[3];
int n, q;
int root = 1;

int level(int u) {
	if (u == root)
		return l[u] = 1;
	if (!l[u])
		l[u] = level(p[0][u]) + 1;
	return l[u];
}

int lca(int x, int y) {
	for (int k = 19; k >= 0; k--) 
		if (l[p[k][x]] >= l[y]) 
			x = p[k][x];
	for (int k = 19; k >= 0; k--)
		if (l[p[k][y]] >= l[x]) 
			y = p[k][y];
	for (int k = 19; k >= 0; k--)
		if (p[k][x] != p[k][y]) {
				x = p[k][x];
				y = p[k][y];
		}
	while (x != y) {
		x = p[0][x];
		y = p[0][y];
	}
	return x; 
}

int dist(int u, int v){
	return abs(u-v);
}

int solve(){
	int mn = 1;
	int tmp;

	for (int i = 0; i < 3; i++)
		for (int j = i+1; j < 3; j++){
			tmp = lca(a[i], a[j]);
			if (l[tmp] > l[mn])
				mn = tmp;
		}
	int ret = 0;
	for (int i = 0; i < 3; i++){
		tmp = lca(mn, a[i]);
		ret = max(ret, dist(l[tmp], l[mn]) + dist(l[tmp], l[a[i]]));
	}
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	cin >> n >> q;
	for (int x, i = 2; i <= n; i++){
		cin >> x;
		p[0][i] = x;
	}
	root = 1;
	for (int i = 1; i <= n; i++)
		level(i);

	for (int k = 1; k <= 19; k++)
		for (int i = 1; i <= n; i++)
			p[k][i] = p[k-1][p[k-1][i]];

	while (q--){
		REP(i,0,3) cin >> a[i];
		cout << solve()+1 << "\n";
	}

	return 0;
}