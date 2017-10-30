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

int t, n;
ll a[MAX];
ll f[MAX];

int calc(int l, int r){
	return (1LL*(a[r] - a[l])*f[r-l-1]);// % MOD;
}

int main(){
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.ou", "wt", stdout);
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
		sort(a,a+n);
		
		ll res = 0;
		ll prev = 0;
		for (int i = 1; i < n; i++){
			prev = ((prev*2) % MOD + (1LL*(f[i]-1LL)*(0LL + a[i] - a[i-1])) % MOD) % MOD;
			res = (res + prev) % MOD;
		}

		cout << "Case #" << cs << ": " << res << "\n";
		cerr << "Done!\n";
	}

	return 0;
}