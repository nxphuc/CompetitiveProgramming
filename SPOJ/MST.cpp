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

const int MAX = 1e4 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

vector< pair<int,int> > a[MAX];
int f[MAX];
int vis[MAX];
int u, v, w;
int n, m;

ll Prim(){
	priority_queue< pair<ll,int>, vector< pair<ll,int> >, greater< pair<ll, int> > > pq;
	ll res = 0;

	memset(f,-1,sizeof(f));
	f[1] = 0;
	pq.push(mp(0, 1));
	while (!pq.empty()){
		u = pq.top().se;
		w = pq.top().fi;
		pq.pop();

		if (vis[u]) continue;
		vis[u] = 1;
		res += w;

		REP(i,0,a[u].size()){
			v = a[u][i].fi;
			w = a[u][i].se;

			if (!vis[v] && (f[v] == -1 || f[v] > w))
				pq.push(mp(f[v] = w, v));
		}
	}
	return res;
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	while (m--){
		cin >> u >> v >> w;
		a[u].pb(mp(v,w));
		a[v].pb(mp(u,w));
	}

	cout << Prim();

	return 0;
}