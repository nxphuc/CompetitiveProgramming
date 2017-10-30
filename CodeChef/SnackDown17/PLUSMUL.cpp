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

ll f[MAX][3];
ll p[MAX];
ll a[MAX];

ll mult(ll a, ll b){
	if (!b)
		return 0;
	if (b == 1)
		return a % MOD;
	ll ret = mult(a, b/2);
	ret = ret*2 + (b & 1 ? a : 0);
	return ret % MOD;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	int t, n;

	p[0] = 1;
	REP(i,1,MAX) p[i] = (p[i-1] << 1) % MOD;

	cin >> t;
	while (t--){
		cin >> n;
		FOR(i,1,n) cin >> a[i];

		f[1][0] = f[1][1] = f[1][2] = a[1];
		for (int i = 2; i <= n; i++){
			f[i][1] = (mult(f[i-1][1], a[i]) + mult(p[i-2], a[i])) % MOD;
			f[i][0] = (f[i-1][2] + f[i][1]) % MOD;
			f[i][2] = (f[i-1][2] + f[i][0]) % MOD;
		}

		cout << f[n][0] << "\n";
	}

	return 0;
}