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

ull n, l, r;
ull f[55];

ll calc(int n, ll x){
	ll ret = 0;
	while (x && n){
		if (x >= (1LL << (n-1))){
			ret += f[n];
			x -= 1LL << (n-1);
		}
		n--;
	}
	return ret;
}

int countBit(ll n){
	int ret = 0;
	while (n){
		ret++;
		n >>= 1;
	}
	return ret;
}

int main(){
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> l >> r;
	
	int m = countBit(n);
	int prev = 0, cur;
	FOR(i,1,m){
		int cur = (n >> (m-i)) & 1;
		f[i] = f[i-1]*2 + cur - prev;
		prev = cur;
	}
	cout << calc(m, r) - calc(m, l-1);

	return 0;
}