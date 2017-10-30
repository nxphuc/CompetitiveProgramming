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

int b[MAX], c[MAX];
vi g[MAX], gt[MAX];
int used[MAX];
vi comp;
stack<int> st;
int n, m, k, x;

void dfs1(int u){
	used[u] = 1;
	REP(i,0,g[u].size()){
		int v = g[u][i];
		if (!used[v])
			dfs1(v);
	}
	st.push(u);
}

int cnt = 0;

void dfs2(int u){
	used[u] = 1;
	REP(i,0,g[u].size()){
		int v = g[u][i];
		if (!used[v])
			dfs2(v);
	}
	comp[u] = cnt;
}

void makeEdge(int x, int u, int v){
	u *= 2; v *= 2;
	if (b[x]){
		g[u].pb(v);
		g[v^1].pb(u^1);
		g[u^1].pb(v^1);
		g[v].pb(u);
	}
	else{
		g[u^1].pb(v);
		g[v^1].pb(u);
		g[u].pb(v^1);
		g[v].pb(u^1);
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	FOR(i,1,n){
		cin >> b[i];
		c[i] = -1;
	}
	REP(i,0,m){
		cin >> k;
		while (k--){
			cin >> x;
			if (c[x] == -1)
				c[x] = i;
			else
				makeEdge(x, c[x], i);
		}
	}

	m <<= 1;
	memset(used, 0, sizeof(used));
	REP(i,0,m)
		if (!used[i])
			dfs1(i);
	comp.assign(m, -1);
	memset(used, 0, sizeof(used));

	while (!st.empty()){
		int u = st.top();
		st.pop();
		if (!used[u]){
			cnt++;
			dfs2(u);
		}
	}

	REP(i,0,m)
		if (comp[i] == comp[i^1]){
			cout << "NO";
			return 0;
		}
	cout << "YES";

	return 0;
}