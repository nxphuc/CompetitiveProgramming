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
const ll inf = 1e10;
const double pi = acos(-1.0);
const double eps = 1e-6;

int t, n, m, k;
int u, v;
ll w;
ll c[110][110];
ii a[5010];
ll f[5010];

void floyd(){
	FOR(k,1,n)
		FOR(u,1,n)
			FOR(v,1,n)
				c[u][v] = min(c[u][v], c[u][k] + c[k][v]);
}

inline ll getPath(int s, int d){ return c[s][d]; }

int main(){
	freopen("test.in", "rt", stdin);
	freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	FOR(cs,1,t){
		cin >> n >> m >> k;

		FOR(i,1,n){
			c[i][i] = 0;
			FOR(j,i+1,n)
				c[i][j] = c[j][i] = inf;
		}

		while (m--){
			cin >> u >> v >> w;
			c[u][v] = c[v][u] = min(min(c[u][v], c[v][u]), w);
		}

		floyd();

		a[0] = mp(1, 1);
		FOR(i,1,k)
			cin >> a[i].fi >> a[i].se;

		f[0] = 0;
		FOR(i,1,k){
			f[i] = f[i-1] + getPath(a[i-1].se, a[i].fi) + getPath(a[i].fi, a[i].se);
			if (i > 1)
				f[i] = min(f[i],
					f[i-2] + getPath(a[i-2].se, a[i-1].fi) + getPath(a[i-1].fi, a[i].fi) + getPath(a[i].fi, a[i-1].se) + getPath(a[i-1].se, a[i].se));
		}

		cout << "Case #" << cs << ": " << (f[k] < inf ? f[k] : -1) << "\n";
	}

	return 0;
}