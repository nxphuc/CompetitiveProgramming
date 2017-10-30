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

const int MAX = 751;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

ii a[MAX];
ll d[MAX][MAX];
ll f[MAX];
int vis[MAX];
int n;

inline ll calcDist(ii a, ii b){
	return (a.fi - b.fi)*(a.fi - b.fi) + (a.se - b.se)*(a.se - b.se);
}

double Prim(){
	priority_queue< pair<ll,int>, vector< pair<ll,int> >, greater< pair<ll, int> > > pq;
	double res = 0;

	memset(f,-1,sizeof(f));
	memset(vis,0,sizeof(vis));
	f[1] = 0;
	pq.push(mp(0, 1));
	while (!pq.empty()){
		int u = pq.top().se;
		int w = pq.top().fi;
		pq.pop();

		if (vis[u]) continue;
		vis[u] = 1;
		res += sqrt(w);

		FOR(v,1,n){
			if (!vis[v] && (f[v] == -1 || f[v] > d[u][v]))
				pq.push(mp(f[v] = d[u][v], v));
		}
	}
	return res;
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int m, u, v;

	while (cin >> n){
		FOR(i,1,n) cin >> a[i].fi >> a[i].se;
		FOR(i,1,n)
			FOR(j,i+1,n)
				d[i][j] = d[j][i] = calcDist(a[i], a[j]);
		cin >> m;
		while (m--){
			cin >> u >> v;
			d[u][v] = d[v][u] = 0;
		}

		cout << fixed << setprecision(2) << Prim() << "\n";
	}

	return 0;
}