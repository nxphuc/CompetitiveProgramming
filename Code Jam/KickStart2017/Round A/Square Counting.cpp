/*
Author: nxphuc
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

inline ll mul(ll a, ll b) { return (a*b) % MOD; }

inline ll add(ll a, ll b) { return (a+b) % MOD; }

inline ll sub(ll a, ll b) { return (a - b + MOD) % MOD; }

ll sumFirstNCube(ll n){
	ll m = n+1;
	if (n & 1)
		m /= 2;
	else
		n /= 2;
	return mul(mul(n, n), mul(m, m));
}

ll sumFirstNSquare(ll n){
	ll m = n+1;
	ll k = 2*n + 1;
	if (n & 1)
		m /= 2;
	else
		n /= 2;
	if (n % 3 == 0)
		n /= 3;
	else
		if (m % 3 == 0)
			m /= 3;
		else
			k /= 3;

	return mul(mul(n, m), k);
}

ll sumFirstN(ll n){
	ll m = n+1;
	if (n & 1)
		m /= 2;
	else
		n /= 2;
	return mul(n, m);
}

ll solve(ll r, ll c){
	ll h = min(r, c) - 1;
	ll res = sumFirstNCube(h);
	res = sub(res, mul(add(r, c), sumFirstNSquare(h)));
	res = add(res, mul(mul(r, c), sumFirstN(h)));
	return res % MOD;
}

int main(){
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	ll T, r, c;

	cin >> T;
	FOR(cs,1,T){
		cin >> r >> c;
		cout << "Case #" << cs << ": " << solve(r, c) << "\n";
	}

	return 0;
}
