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

int t, n, res;
int a[MAX];
int f[MAX];

int fpow(int b, int p){
	if (!p)
		return 1;
	ll res = fpow(b, p/2);
	res = (res*res) % MOD;
	if (p & 1)
		res = (res*b) % MOD;
	return res;
}

int calc(int l, int r){
	return 1LL*(a[r] - a[l])*f[r-l-1] % MOD;
}

int main(){
	freopen("A-large.in", "rt", stdin);
	freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	f[0] = 1;
	REP(i,1,MAX)
		f[i] = (f[i-1]*2) % MOD;

	cin >> t;
	FOR(cs,1,t){
		cerr << "Case " << cs << ": ";
		cin >> n;
		REP(i,0,n)
			cin >> a[i];
		// sort(a,a+n);
		// res = f[0] = 0;
		// REP(i,1,n){
		// 	f[i] = (f[i-1] + (a[i] - a[i-1])*i) % MOD;
		// 	res = (res + f[i]) % MOD;
		// }
		// cout << "\n";
		// REP(i,0,n)
		// 	cerr << f[i] << " ";
		// cout << "\n";
		res = 0;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++){
				res = (res + calc(i, j)) % MOD;
			}

		cout << "Case #" << cs << ": " << res << "\n";
		cerr << "Done!\n";
	}

	return 0;
}