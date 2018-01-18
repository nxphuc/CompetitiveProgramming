#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

ll fastPow(ll b, ll p){
	if (!p) return 1;
	ll ret = fastPow(b, p/2);
	ret = (ret*ret) % MOD;
	if (p & 1) ret = (ret*b) % MOD;
	return ret;
}

ll combin(ll n, ll k){
	ll ret = 1;

	for (int i = 1, j = n-k+1; i <= k; i++, j++){
		ret = (ret * j) % MOD;
		ret = (ret * fastPow(i, MOD-2)) % MOD;
	}
	return ret;
}

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	ll a, b, c;

	cin >> a >> b >> c;
	if (c-1 != a || b > a)
		cout << 0;
	else{
		cout << (fastPow(2,b)*combin(a, b)) % MOD;
	}

	return 0;
}