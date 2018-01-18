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

const int MAX = 1e3 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n;
int a[MAX], b[MAX];
int f[MAX][MAX];

int main(){
	// freopen("test.in", "rt", stdin);
	freopen("nocross.in", "rt", stdin);
	freopen("nocross.out", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> n;
	FOR(i,1,n) cin >> a[i];
	FOR(i,1,n){
		int x;
		cin >> x;
		b[x] = i;
	}

	// memset(f,-1,sizeof(f));
	f[0][0] = 0;
	FOR(i,1,n){
		// f[i][0] = 1;
		FOR(j,1,n)
			f[i][j] = f[i-1][j];
		FOR(j,max(1,a[i]-4),min(n,a[i]+4))
			f[i][b[j]] = max(f[i][b[j]], f[i-1][b[j]-1] + 1);
		FOR(j,1,n)
			f[i][j] = max(f[i][j], f[i][j-1]);
	}
	cout << f[n][n];

	return 0;
}