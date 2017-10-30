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

const int MAX = 2e5 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll a[MAX];
pair<ii,int> q[MAX];
ll f[MAX];
int n, m, l, r;

ll fPow(ll b, ll p){
	if (!p)
		return 1;
	ll r = fPow(b, p/2);
	r = (r*r) % MOD;
	if (p & 1)
		r = (r*b) % MOD;
	return r;
}

ll mul(ll a, ll b){
	return (a*fPow(b, MOD-2)) % MOD;
}

map<ll,ll> dp;

ll phi(ll n){
	if (dp.find(n) != dp.end())
		return dp[n];
	ll result = n;
	for (ll i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return dp[n] = result;	
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	a[0] = 1;
	cin >> n;
	FOR(i,1,n){
		cin >> a[i];
		a[i] = (a[i-1]*a[i]) % MOD;
	}

	cin >> m;
	REP(i,0,m)
		cin >> q[i].fi.fi >> q[i].fi.se >> q[i].se;
	sort(q, q+m);
	int l = 0, r = 0;
	

	return 0;
}