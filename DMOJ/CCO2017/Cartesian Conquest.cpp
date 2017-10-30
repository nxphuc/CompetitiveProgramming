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
const ll inf = 1e8;
const double pi = acos(-1.0);
const double eps = 1e-6;

map<ll,int> mpMin, mpMax;

ll getHashValue(ll n, ll m) {
	return n*inf + m;
}

int dpMin(ll n, ll m){
	ll key = getHashValue(n, m);
	if (n > m) swap(n, m);
	if (!n || !m)
		return mpMin[key] = 0;
	if (n*2 == m)
		return mpMin[key] = 1;
	if (n == 1)
		return mpMin[key] = m/2;
	if (mpMin.find(key) != mpMin.end())
		return mpMin[key];
	mpMin[key] = inf;
	if (!(n & 1) && n/2 <= m)
		mpMin[key] = min(mpMin[key], dpMin(n, m - n/2) + 1);
	if (n*2 <= m)
		mpMin[key] = min(mpMin[key], dpMin(n, m - n*2) + 1);
	if (!(m & 1) && m/2 <= n)
		mpMin[key] = min(mpMin[key], dpMin(n - m/2, m) + 1);
	return mpMin[key];
}

int dpMax(ll n, ll m){
	ll key = getHashValue(n, m);
	if (n > m) swap(n, m);
	if (!n || !m)
		return mpMax[key] = 0;
	if (n == 1)
		return mpMax[key] = m/2LL;
	
	if (mpMax.find(key) != mpMax.end())
		return mpMax[key];
	mpMax[key] = -inf;
	if (!(n & 1) && n/2 <= m){
		mpMax[key] = max(mpMax[key], dpMax(n, m - n/2) + 1);
	}
	if (n*2 <= m)
		mpMax[key] = max(mpMax[key], dpMax(n, m - n*2) + 1);
	if (!(m & 1) && m/2 <= n)
		mpMax[key] = max(mpMax[key], dpMax(n - m/2, m) + 1);
	return mpMax[key];
}

int dp2(ll n, ll m){
	if (n > m) swap(n, m);
	if (!n) return 0;
	if (n == 1)
		return m/2;
	if (n & 1){
		ll k = m/(2*n);
		if (k)
			return dp2(n, m - 2*k*n) + k;
		else
			return dp2(n - m/2, m) + 1;
	}
	else{
		int res = dp2(n, m - n/2) + 1;
		if (m % 2 == 0 && n >= m/2)
			res = max(res, dp2(n - m/2, m) + 1);
		return res;
	}
}

int dp1(ll n, ll m){
	if (n > m) swap(n, m);
	if (n*2 == m)
		return 1;
	if (!n) return 0;
	if (n == 1)
		return m/2;

	if (n*2 <= m){
		int res = dp1(n, m - 2*n) + 1;
		// if (n % 2 == 0)
		// 	res = min(res, dp1(n, m - n/2) + 1);
		return res;
	}
	else{
		int res = inf;
		if (m % 2 == 0)
			res = min(res, dp1(n - m/2, m) + 1);
		if (n % 2 == 0)
			res = min(res, dp1(n, m - n/2) + 1);
		return res;
	}
}

int main(){
	freopen("test.in", "rt", stdin);
	freopen("test2.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	ll n, m;
	// cin >> n >> m;
	// cout << dpMin(n, m) << " " << dpMax(n, m);
	// cout << "\n";
	// cout << dp2(4, 3) << "\n";
	// return 0;
	// REP(i,0,100)
	// 	cerr << dpMin(i, 1000000-i) << "\n";
	// cout << dp2(2, 1000000-2);
	// return 0;
	// for (int i = 2; i <= 1000; i += 2){
	// 	FOR(j,1,1000){
	// 		int u = dpMin(i, j);
	// 		int v = dp1(i, j);
	// 		if (u != v){
	// 			cout << "Error in test " << i << " " << j << "\n";
	// 			cout << "Result: " << u << ", found: " << v << "\n";
	// 		}
	// 		// cerr << "Done " << i << " " << j << "\n";
	// 	}
	// 	cerr << "Done " << i << "\n";
	// }
	// return 0;
	// cout << dp2(n, m);
	cout << "     ";
	for (int j = 1; j <= 40; j++)
		cout << fixed << setw(2) << j << " ";
	cout << "\n";
	for (int i = 2; i <= 100; i += 2){
		cout << "#" << fixed << setw(2) << i << ": ";
		for (int j = 1; j <= 40; j++)
			cout << fixed << setw(2) << dpMax(i, j) << " ";
		cout << "\n";
	}

	return 0;
}
