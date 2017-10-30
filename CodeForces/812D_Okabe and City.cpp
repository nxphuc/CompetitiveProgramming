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

const int MAX = 1e5 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[12] = {-1, 0, 0, 1, -1, -2, -1, 0, 1, 2, 1, 0};
int dy[12] = {0, -1, 1, 0, -1, 0, 1, 2, 1, 0, -1, -2};

map< ii, int> pmap;
ii p[MAX];
int f[MAX];
int n, m, k;

int inBoard(int x, int y){
	return 0 < x && x <= n && 0 < y && y <= m;
}

void dijkstra(ii src){
	priority_queue< ii, vector< ii >, greater< ii > > pq;
	int u, v, x, y, id, w;
	ii tmp;

	memset(f,-1,sizeof(f));
	f[pmap[src]] = 0;
	pq.push(mp(0, pmap[src]));
	while (!pq.empty()){
		tmp = pq.top();
		pq.pop();

		u = p[tmp.se].fi;
		v = p[tmp.se].se;
		w = tmp.fi;
		for (int i = 0; i < 4; i++){
			x = u + dx[i];
			y = v + dy[i];
			tmp = mp(x, y);
			if (inBoard(x, y) && pmap.find(tmp) != pmap.end()){
				id = pmap[tmp];
				if (f[id] == -1 || f[id] > w){
					f[id] = w;
					pq.push(mp(w, id));
				}
			}
		}
		for (int i = 4; i < 12; i++){
			x = u + dx[i];
			y = v + dy[i];
			tmp = mp(x, y);
			if (inBoard(x, y) && pmap.find(tmp) != pmap.end()){
				id = pmap[tmp];
				if (f[id] == -1 || f[id] > w + 1){
					f[id] = w + 1;
					pq.push(mp(w + 1, id));
				}
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	REP(i,0,k){
		cin >> p[i].fi >> p[i].se;
		pmap[p[i]] = i;
	}
	ii src = mp(0, 0);
	dijkstra(src);
	if (pmap.find(mp(n, m)) != pmap.end())
		cout << f[pmap[mp(n, m)]];
	else{
		int res = inf;
		for (int i = 1; i <= m; i++){
			if (pmap.find(mp(n, i)) != pmap.end() && f[pmap[mp(n, i)]] != -1){
				cout << "@" << n << " " << i << ": ";
				cout << pmap[mp(n, i)] + 1 << "\n";
				res = min(res, pmap[mp(n, i)] + 1);
			}
			if (pmap.find(mp(n-1, i)) != pmap.end() && f[pmap[mp(n-1, i)]] != -1){
				cout << "#" << n-1 << " " << i << ": ";
				cout << pmap[mp(n-1, i)] + 1 << "\n";
				res = min(res, pmap[mp(n-1, i)] + 1);
			}
		}
		for (int i = 1; i <= n; i++){
			if (pmap.find(mp(i, m)) != pmap.end() && f[pmap[mp(i, m)]] != -1){
				cout << "$" << i << " " << m << ": ";
				cout << pmap[mp(i, m)] + 1 << "\n";
				res = min(res, pmap[mp(i, m)] + 1);
			}
			if (pmap.find(mp(i, m-1)) != pmap.end() && f[pmap[mp(i, m-1)]] != -1){
				cout << "&" << i << " " << m-1 << ": ";
				cout << pmap[mp(i, m-1)] + 1 << "\n";
				res = min(res, pmap[mp(i, m-1)] + 1);
			}
		}

		if (res == inf)
			cout << -1;
		else
			cout << res;
	}
	for (int i = 0; i < k; i++)

	return 0;
}