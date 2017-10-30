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

const int MAX = 1e6 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

vi a[MAX];
int n, k;
ull f[MAX];
ull cnt[MAX];
ull s[MAX];
ull g[MAX][5];

void dfs(int u, int prev){
	int v;
	cnt[u] = 1;
	g[u][0] = 1;
	for (int i = 0; i < a[u].size(); i++){
		v = a[u][i];
		if (v == prev) continue;
		dfs(v, u);

		f[u] += f[v];
		f[u] += s[u]*cnt[v] + cnt[u]*s[v];
		for (int p = 0; p < k; p++)
			for (int q = 0; q < k; q++)
				f[u] += g[u][p] * g[v][q] * (1 + (p + q + 1 > k));

		for (int j = 0; j < k; j++)
			g[u][(j + 1) % k] += g[v][j];
		s[u] += s[v];
		s[u] += g[v][k-1];
		cnt[u] += cnt[v];
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int u, v;
	cin >> n >> k;
	REP(i,1,n){
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}

	dfs(1, -1);
	ull res = 0;
	FOR(i,1,n){
		res += f[i];
		REP(j,1,k)
			res += g[i][j];
	}
	// cout << "f: ";
	// FOR(i,1,n)
	// 	cout << f[i] << " ";
	// cout << "\ns: ";
	// FOR(i,1,n)
	// 	cout << s[i] << " ";
	// cout << "\ncnt: ";
	// FOR(i,1,n)
	// 	cout << cnt[i] << " ";
	// cout << "\n";
	cout << f[1];

	return 0;
}
