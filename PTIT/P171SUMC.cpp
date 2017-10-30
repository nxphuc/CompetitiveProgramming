#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

ll fastPow(ll b, ll p){
	if (!p)
		return 1;
	ll ret = fastPow(b, p/2);
	ret = (ret*ret) % MOD;
	if (p & 1)
		ret = (ret*b) % MOD;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	ll res = 1;
	for (int i = 1; i <= n; i++)
		res = (res * i) % MOD;
	res = fastPow(res, MOD-2);
	for (int i = n; i < 2*n; i++)
		res = (res * i) % MOD;
	cout << (res*2-n + MOD) % MOD;

	return 0;
}