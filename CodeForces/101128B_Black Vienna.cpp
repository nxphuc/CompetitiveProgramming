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

const int MAX = 60;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

vi g[MAX];
int used[MAX], f[MAX];
string s[MAX];
int a[MAX], b[MAX];
int n, m;
int cnt;
int st[MAX];

/*
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
*/

void makeEdge(int x, int y, int u, int v){
	u = u*2 + x;
	v = v*2 + y;
	g[u^1].push_back(v);
	g[v^1].push_back(u);
}

int dfs(int u){
	if (used[u^1]) return 0;
	if (used[u]) return 1;
	used[u] = 1;
	st[cnt++] = u;
	for (int v: g[u])
		if (!dfs(v))
			return 0;
	return 1;
}

int isBlackVienna(int x, int y, int z){
	memset(f,0,sizeof(f));
	f[x] = f[y] = f[z] = 1;
	for (int i = 0; i < m; i++) g[i].clear();

	for (int i = 0; i < n; i++){
		switch (b[i]){
			case 0:
				if (f[s[i][0]] && f[s[i][1]]) continue;
				if (!f[s[i][0]]) makeEdge(a[i]^1, a[i]^1, s[i][0], s[i][0]);
				if (!f[s[i][1]]) makeEdge(a[i]^1, a[i]^1, s[i][1], s[i][1]);
				break;
			case 1:
				if (f[s[i][0]] && f[s[i][1]]) return 0;
				else
					if (f[s[i][0]])
						makeEdge(a[i], a[i], s[i][1], s[i][1]);
					else
						if (f[s[i][1]])
							makeEdge(a[i], a[i], s[i][0], s[i][0]);
						else{
							makeEdge(a[i], a[i], s[i][0], s[i][1]);
							makeEdge(a[i]^1, a[i]^1, s[i][0], s[i][1]);
						}
				break;
			case 2:
				if (f[s[i][0]] || f[s[i][1]])
					return 0;
				makeEdge(a[i], a[i], s[i][0], s[i][0]);
				makeEdge(a[i], a[i], s[i][1], s[i][1]);
				break;
		}
	}

	memset(used, 0, sizeof(used));
	for (int i = 0; i < 52; i += 2)
		if (!used[i] && !used[i^1]){
			cnt = 0;
			if (!dfs(i)){
				while (cnt) used[st[--cnt]] = 0;
				if (!dfs(i+1)) return 0;
			}
		}
	return 1;
}


int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> n;
	m = 52;
	for (int i = 0; i < n; i++){
		cin >> s[i] >> a[i] >> b[i];
		s[i][0] -= 'A';
		s[i][1] -= 'A';
		a[i]--;
	}

	int res = 0;
	for (int i = 0; i < 26; i++)
		for (int j = i+1; j < 26; j++)
			for (int k = j+1; k < 26; k++)
				res += isBlackVienna(i, j, k);
	cout << res;

	return 0;
}