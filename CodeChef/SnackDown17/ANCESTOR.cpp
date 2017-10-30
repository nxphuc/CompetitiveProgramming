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

const int MAX = 5e5 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, t;
vector <ii>  ed[MAX];
int d[MAX], Size[MAX], pa[MAX][20];
int Head[MAX], inChain[MAX], nChain, nEdge, Edge[MAX];
int Base[MAX], Value[MAX], Pos[MAX], IT[MAX *4];

vector<int> graph[MAX];
int f[MAX];

int get_Tree(int i, int l, int r, int x, int y){
	if (l > r || l > y ||x > r) return 0;
	if (l >= x && r <= y) return IT[i];
	int mid =(l+r) >> 1;
	int i1 = i << 1;
	return get_Tree(i1, l , mid, x, y) + get_Tree(i1+1, mid+1, r, x,y);
}

void make_Tree(int i, int l, int r) {
	if (l > r) return;
	if (l == r ) {
			IT[i] = Base[l];
			return;
	}
	int mid =(l+r) >> 1;
	int i1 = i << 1;
	make_Tree(i1, l, mid);
	make_Tree(i1+1, mid+1, r);
	IT[i] = IT[i1] + IT[i1+1];
}

void Update_Tree(int i, int l, int r, int x, int val){
	if (l > r || l > x || r < x) return;
	if (l == r && l == x){
		IT[i] += val;
		return;
	}
	int mid =(l+r) >> 1;
	int i1 = i << 1;
	Update_Tree(i1, l, mid, x, val);
	Update_Tree(i1+1, mid+1, r, x, val);
	IT[i] = IT[i1] + IT[i1+1];
}

void HLD(int u){
	if (Head[nChain] == -1) Head[nChain] = u;
	inChain [u] = nChain;

	Base[nEdge] = Value[Edge[u]];
	Pos[Edge[u]] = nEdge++;

	int Choose = -1;
	REP(i, 0, ed[u].size()){
		int v = ed[u][i].first;
		if (pa[u][0] == v) continue;
		if (Choose == -1 || Size[v] > Size[Choose])
			Choose = v;
	}

	if (Choose == -1 )  return; // u = leaf

	HLD(Choose);

	REP(i,0,ed[u].size()){
		int v = ed[u][i].first;
		if (pa[u][0] == v) continue;
		if (v == Choose) continue;
		nChain ++;
		HLD(v);
	}
}

int Cal(int u, int v){
	int result = 0;
	int cv = inChain[v], cu;
	while (1){
		cu= inChain[u];
		if (cu == cv){
			if (u==v) return result;
			int kk = get_Tree(1, 1, nEdge, Pos[Edge[v]]+1, Pos[Edge[u]]);
			result += kk;
			return result;
		}
		int kk = get_Tree(1, 1, nEdge, Pos[Edge[Head[cu]]], Pos[Edge[u]]);
		result += kk;
		u = pa[Head[cu]][0];
	}
	return result;
}

void DFS(int u){
	Size[u] = 1;
	REP(i,0,ed[u].size()){
		int v = ed[u][i].first ;
		if (pa[v][0] != 0) continue;
		d[v] = d[u] + 1;
		pa[v][0] = u;
		Edge[ v] = ed[u][i].second;
		DFS(v);
		Size[u] += Size[v];
	}
}

int getbit(int x, int k ){
	return (x>>k)&1;
}

void Set_LCA(){
	REP(j,1,20)
		FOR(i,1,n)
			pa[i][j] = pa[pa[i][j-1]][j-1];
}

int LCA(int u, int v){
	if (u== v) return u;
	if (d[u]< d[v] )  swap(u, v);
	int x = d[u] - d[v];
	FOD(j,19,0) if (getbit(x, j))   u = pa[u][j];
	if (u ==v)  return u;
	FOD(j,19,0)
		if (pa[u][j] != pa[v][j]){
			u = pa[u][j]; v = pa[v][j];
		}
	return pa[u][0];
}

void Init(){
	FOR(i,1,n){
		REP(j,0,20)  pa[i][j] = 0;
		Head[i] = -1;
		ed[i].clear();
	}
	d[1] = 0;
	pa[1][0] = 1;
	Edge[1] =0 ;
}

void dfsGraph(int u, int prv){
	for (int v : graph[u])
		if (v != prv){
			Update_Tree(1, 1, nEdge, Pos[Edge[v]], 1);
			f[v] = Cal(v, 1);
			dfsGraph(v, u);
			Update_Tree(1, 1, nEdge, Pos[Edge[v]], -1);
		}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	int u, v;

	cin >> t;
	while (t--){
		cin >> n;

		Init();

		REP(i,1,n){
			cin >> u >> v;
			ed[u].pb(mp(v, i));
			ed[v].pb(mp(u, i));
			Value[i] = 0;
		}

		pa[1][0] = 1;
		DFS(1);
		Set_LCA();
		nChain = 1;
		nEdge = 0;
		HLD(1);
		make_Tree(1, 1, nEdge);

		FOR(i,1,n)
			graph[i].clear();
		REP(i,1,n){
			cin >> u >> v;
			graph[u].pb(v);
			graph[v].pb(u);
		}
		dfsGraph(1, 0);
		FOR(i,1,n)
			cout << f[i] << " ";
		cout << "\n";
	}

	return 0;
}