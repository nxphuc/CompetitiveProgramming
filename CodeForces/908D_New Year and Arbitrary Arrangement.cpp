// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// const int MAX = 3e3 + 10;
// const int MOD = 1e9 + 7;
// const int INF = 1e9;
// const double pi = acos(-1.0);
// const double EPS = 1e-6;

// int gcd(ll a, ll b) {
// 	while (a * b) {
// 		if (a > b)
// 			a %= b;
// 		else
// 			b %= a;
// 	}
// 	return a+b;
// }

// int k, pa, pb;
// ll a, b;
// ll f[MAX][MAX];

// ll fastPow(ll b, ll p) {
// 	if (!p) {
// 		return 1;
// 	}
// 	ll ret = fastPow(b, p >> 1);
// 	ret = (ret * ret) % MOD;
// 	if (p & 1) {
// 		ret = (ret * b) % MOD;
// 	}
// 	return ret;
// }

// ll calcDiv(ll a, ll b) {
// 	ll g = gcd(a, b);
// 	a /= g;
// 	b = fastPow(b / g, MOD-2);
// 	return a * b % MOD;
// }

// ll dp(int k, int na) {
// 	if (f[k][na] != -1) {
// 		return f[k][na];
// 	}
// 	if (!na) {
// 		return f[k][na] = 0;
// 	}
// 	if (!k) {
// 		return f[k][na] = fastPow(a, na);
// 	}
// 	f[k][na] = (dp(k, na-1) * a) % MOD;
// 	if (k >= na) {
// 		f[k][na] = (f[k][na] + dp(k - na, na) * b) % MOD;
// 	}
// 	return f[k][na];
// }

// int main(){
// 	freopen("test.in", "rt", stdin);
// 	ios::sync_with_stdio(false);

// 	cin >> k >> pa >> pb;
// 	a = calcDiv(pa, pa + pb);
// 	b = calcDiv(pb, pa + pb);
// 	ll res = 0;

// 	memset(f, -1, sizeof(f));
// 	for (int i = k; i <= min(3*k, 3000); i++)
// 		for (int j = 1; j <= 3000; j++)
// 			dp(i, j);
// 	for (int i = k; i <= k+10; i++) {
// 		cout << f[i][3000] << " ";
// 	}
	
// 	return 0;
// }