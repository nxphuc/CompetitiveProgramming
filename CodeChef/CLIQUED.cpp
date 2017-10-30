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

int t, n, k, m, s;
ll x;
ll f[MAX];
vector< pair<int,ll> > a[MAX];

void Dijkstra(int s){
	priority_queue< pair<ll,int>, vector< pair<ll,int> >, greater< pair<ll,int> > > pq;
	int u, v;
	int flag = 0;
	ll w, p;

	pq.push(mp(0, s));
	f[s] = 0;
	if (s <= k){
		FOR(i,1,k)
			if (i != s){
				pq.push(mp(x, i));
				f[i] = x;
			}
	}
	while (!pq.empty()){
		p = pq.top().fi;
		u = pq.top().se;
		pq.pop();

		if (p != f[u]) continue;
		REP(i,0,a[u].size()){
			v = a[u][i].fi;
			w = a[u][i].se;

			if (p + w < f[v]){
				f[v] = p+w;
				pq.push(mp(f[v], v));
			}
		}
		if (u <= k && !flag){
			FOR(i,1,k)
				if (f[i] > p + x){
					f[i] = p + x;
					pq.push(mp(f[i], i));
				}
			flag = 1;
		}
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> k >> x >> m >> s;
		FOR(i,1,n){
			f[i] = 1e15;
			a[i].clear();
		}

		int u, v;
		ll w;
		while (m--){
			cin >> u >> v >> w;
			a[u].pb(mp(v, w));
			a[v].pb(mp(u, w));
		}
		Dijkstra(s);
		ll mnK = 1e15;
		FOR(i,1,k)
			mnK = min(mnK, f[i]);
		FOR(i,1,n)
			if (i <= k)
				cout << min(mnK+x, f[i]) << " ";
			else
				cout << f[i] << " ";
		cout << "\n";
	}

	return 0;
}