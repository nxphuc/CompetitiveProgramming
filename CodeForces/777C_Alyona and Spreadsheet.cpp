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

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	vector< vector<int> > a, g;
	vector<int> f;
	int n, m;

	cin >> n >> m;

	a.resize(n+1);
	g.resize(n+1);
	f.resize(n+1);
	a[0].assign(m+1, 0);
	g[0].assign(m+1, 0);
	FOR(i,1,n){
		a[i].assign(m+1, 0);
		g[i].assign(m+1, 0);
		f[i] = 0;
		FOR(j,1,m){
			cin >> a[i][j];
			g[i][j] = a[i][j] >= a[i-1][j] ? g[i-1][j] + 1 : 1;
			f[i] = max(f[i], g[i][j]);
		}
	}

	int q, l, r;
	cin >> q;
	while (q--){
		cin >> l >> r;
		cout << (f[r] >= (r-l+1) ? "Yes\n" : "No\n");
	}

	return 0;
}