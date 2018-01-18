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
#define Ele pair<ll, ii>

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

const int MAX = 110;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int a[MAX][MAX];
int n, t;
int u, v;
ll f[MAX*MAX][3];
vector<ii> adj[MAX*MAX];

inline int inBoard(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < n;
}

void dijkstra(int s){
	priority_queue< Ele, vector<Ele>, greater<Ele> > pq;

	pq.push(mp(0, mp(0, 0)));
	while (!pq.empty()){
		Ele cur = pq.top();
		pq.pop();
		if (cur.fi != f[cur.se.fi][cur.se.se])
			continue;
		
		REP(i,0,adj[cur.se.fi].size()){
			u = adj[cur.se.fi][i].fi;
			v = adj[cur.se.fi][i].se + cur.fi + (cur.se.se == 2 ? a[u/n][u%n] : 0);
			if (f[u][(cur.se.se + 1) % 3] == -1 || f[u][(cur.se.se + 1) % 3] > v){
				f[u][(cur.se.se + 1) % 3] = v;
				pq.push(mp(v, mp(u, (cur.se.se + 1) % 3)));
			}
		}
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	freopen("visitfj.in", "rt", stdin);
	freopen("visitfj.out", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> n >> t;
	REP(i,0,n)
		REP(j,0,n)
			cin >> a[i][j];
	REP(i,0,n)
		REP(j,0,n){
			u = i*n+j;
			REP(d,0,4){
				if (!inBoard(i+dx[d], j+dy[d]))
					continue;
				v = (i + dx[d])*n + j + dy[d];
				adj[u].pb(mp(v, t));
				adj[v].pb(mp(u, t));
			}
		}
	memset(f,-1,sizeof(f));
	f[0][0] = 0;
	dijkstra(0);
	cout << min(f[n*n-1][0], min(f[n*n-1][1], f[n*n-1][2]));

	return 0;
}