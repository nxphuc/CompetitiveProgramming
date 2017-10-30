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
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

vii a[MAX];
pair<ll,int> f[MAX][2];
ll res[MAX], d[MAX];
int vis[MAX], nxt[MAX];
int n, m, r, val;

void findRes(int curNode, int parNode, ll dis){
	res[curNode] = max(dis, f[curNode][0].fi);
	REP(i,0,sz(a[curNode]))
		if (a[curNode][i].fi != parNode && vis[a[curNode][i].fi]){
			if (a[curNode][i].fi != f[curNode][0].se)
				findRes(a[curNode][i].fi, curNode, max(f[curNode][0].fi, dis) + a[curNode][i].se);
			else
				findRes(a[curNode][i].fi, curNode, max(f[curNode][1].fi, dis) + a[curNode][i].se);
		}
}

void solve(int curNode, int nxtNode, int parNode, ll dis){
	d[curNode] = dis;
	nxt[curNode] = nxtNode;
	REP(i,0,sz(a[curNode]))
		if (a[curNode][i].fi != parNode){
			if (!vis[a[curNode][i].fi])
				solve(a[curNode][i].fi, nxtNode, curNode, dis + a[curNode][i].se);
			else
				solve(a[curNode][i].fi, a[curNode][i].fi, curNode, 0);
		}
}

ll process(int curNode, int parNode){
	ll tmp;
	REP(i,0,sz(a[curNode])){
		if (a[curNode][i].fi != parNode && vis[a[curNode][i].fi]){
			tmp = process(a[curNode][i].fi, curNode) + a[curNode][i].se;
			if (tmp > f[curNode][1].fi){
				f[curNode][1].fi = tmp;
				f[curNode][1].se = a[curNode][i].fi;
			}
			if (f[curNode][1].fi > f[curNode][0].fi) swap(f[curNode][0], f[curNode][1]);
		}
	}
	return f[curNode][0].fi;
}

bool calc(int curNode, int parNode){
	REP(i,0,sz(a[curNode])){
		if (a[curNode][i].fi != parNode){
			if (calc(a[curNode][i].fi, curNode)){
				val += a[curNode][i].se;
				vis[curNode] = 1;
			}
		}
	}
	return vis[curNode];
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int u, v;

	cin >> n >> m;
	REP(i,1,n){
		cin >> u >> v;
		a[u].pb(mp(v, 1));
		a[v].pb(mp(u, 1));
	}

	REP(i,0,m){
		cin >> u;
		vis[u] = 1;
		r = u;
	}

	calc(r,0);
	FOR(i,1,n)
		if (vis[i]){
			r = i;
			break;
		}

	process(r,0);
	solve(r,r,0,0);
	findRes(r,0,0);

	ll resVal, tmpVal;
	int resId;
	resVal = resId = -1;
	FOR(i,1,n){
		tmpVal = 2*val + d[i] - res[nxt[i]];
		if (resVal == -1 || tmpVal < resVal){
			resVal = tmpVal;
			resId = i;
		}
	}

	cout << resId << endl << resVal;

	return 0;
}