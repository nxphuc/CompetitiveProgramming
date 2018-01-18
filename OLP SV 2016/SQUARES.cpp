#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

inline ll mul(ll a, ll b){ return a*b % MOD; }

inline ll sub(ll a, ll b){ return (a-b+MOD) % MOD; }

ll fastPow(ll b, ll p){
	if (!p)
		return 1;
	ll ret = fastPow(b, p/2);
	ret = mul(ret, ret);
	if (p & 1)
		ret = mul(ret, b);
	return ret;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	ll n, l;

	cin >> n >> l;
	cout << mul(mul(mul(l, l), sub(fastPow(4, n+1), 1)), fastPow(3, MOD-2));

	return 0;
}