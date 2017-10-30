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

vi g[MAX];
int used[MAX];
vi comp;
stack<int> st;
int n, m, M, k, x, u, v;

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
	if (x){
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

void input(){
	M = n*m*4;
	cnt = 0;

	for (int i = 0; i <= 5*n*m; i++)
		g[i].clear();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> x >> u >> v;
			u += i*m;
			v += n*m + j*n;
			makeEdge(x, u, v);
		}
	}
}

void solve(){
	memset(used, 0, sizeof(used));
	REP(i,0,M)
		if (!used[i])
			dfs1(i);
	comp.assign(M, -1);
	memset(used, 0, sizeof(used));

	while (!st.empty()){
		int u = st.top();
		st.pop();
		if (!used[u]){
			cnt++;
			dfs2(u);
		}
	}
}

int getIndex(int u){
	u >>= 1;
	if (u >= n*m){
		cout << "C";
		u -= n*m;
		cout << setw(2) << setfill('0') << u/n << setw(2) << setfill('0') << u%n << " ";
	}
	else{
		cout << "R";
		cout << fixed << setw(2) << setfill('0') << u/m << setw(2) << setfill('0') << u%m << " ";
		// cout << u/m << " " << u%m << " ";
	}
}

void printResult(){
	REP(i,0,M)
		if (comp[i] == comp[i^1]){
			cout << "Impossible\n";
			return;
		}
	// REP(i,0,M) cout << comp[i] << " " << (i/2/m) << " " << (i/2) % m << "\n";
	for (int i = 0; i < M; i+=2)
		if (g[i].size() && g[i^1].size()){
			// if (comp[i] > comp[i^1])
			// 	getIndex(i);
			// else
			// 	getIndex(i^1);
			// cout << (comp[i] > comp[i^1] ? i : i^1) << "\n";
			// if (comp[i] > comp[i^1])
			// {
			// 	getIndex(i);
			// 	cout << comp[i] << "\n";
			// }
			// // else
			// {
			// 	getIndex(i^1);
			// 	cout << comp[i^1] << "\n";
			// }
			if (comp[i^1] > comp[i])
				getIndex(i^1);
		}
	cout << "\n";
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int cs = 1; cs <= t; cs++){
		cout << "Case #" << cs << "\n";
		cin >> n >> m;
		
		input();
		solve();
		printResult();
	}

	return 0;
}