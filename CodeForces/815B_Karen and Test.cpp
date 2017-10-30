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

ll mult(ll a, ll b){
	if (!b) return 0;

	ll ret = mult(a, b/2);
	ret <<= 1;
	if (b & 1) ret += a;
	while (ret >= MOD) ret -= MOD;
	return ret;
}

ll myPow(ll b, ll p){
	if (!p) return 1;

	ll ret = myPow(b, p/2);
	ret = (ret*ret) % MOD;
	if (p & 1) ret = (ret*b) % MOD;
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	ll n, x, sign, combin;
	ll res = 0;

	cin >> n >> res;
	
	--n;
	res %= MOD;
	combin = sign = 1;

	FOR(i,1,n){
		cin >> x;
		if (i % 2 == 0) sign *= -1;
		combin = (mult(combin, n-i+1) * myPow(i, MOD-2)) % MOD;
		cout << sign << " " << combin << " " << x << "\n";
		res = (res + sign*combin*x) % MOD;
	}
	cout << res;

	return 0;
}