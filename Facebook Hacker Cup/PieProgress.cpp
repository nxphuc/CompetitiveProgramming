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

const int MAX = 310;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const ll inf = 1e15;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, m, t;
ll a[MAX][MAX];
ll f[MAX][MAX];

ll dp(int days, int pies){
	if (f[days][pies] != -1)
		return f[days][pies];
	if (!days)
		return pies ? inf : 0;
	f[days][pies] = inf;

	FOR(i,0,m){
		if (pies - i < days-1)
			break;
		f[days][pies] = min(f[days][pies], dp(days-1, pies - i) + a[days][i] + 1LL*i*i);
	}
	return f[days][pies];
}

int main(){
	freopen("pie_progress.txt", "rt", stdin);
	freopen("pie_progress.out", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	FOR(cs,1,t){
		cin >> n >> m;
		FOR(i,1,n){
			FOR(j,1,m)
				cin >> a[i][j];
			sort(a[i]+1, a[i]+m+1);
			FOR(j,1,m)
				a[i][j] += a[i][j-1];
		}
		memset(f,-1,sizeof(f));
		cout << "Case #" << cs << ": " << dp(n,n) << "\n";
	}

	return 0;
}