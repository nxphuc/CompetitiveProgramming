#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;
 
int a[MAX], b[MAX], c[MAX];
int t, na, nb, nc;
ll sa, sc;
ll res;
 
inline ll mult(ll x, ll y){
	return x*y % MOD;
}
 
ll getSum(ll x, ll y, ll z, ll nx, ll nz){
	return (mult(mult(y,y), mult(nx, nz)) + mult(y, (mult(nz, x) + mult(nx, z)) % MOD) + mult(x, z)) % MOD;
	return (((y*y % MOD)*(nx*nz % MOD)) % MOD + y*((nz*x+nx*z) % MOD) % MOD + x*z % MOD) % MOD;
}
 
int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);
 
	cin >> t;
	while (t--){
		cin >> na >> nb >> nc;
		for (int i = 0; i < na; i++)
			cin >> a[i];
		for (int i = 0; i < nb; i++)
			cin >> b[i];
		for (int i = 0; i < nc; i++)
			cin >> c[i];              
 
		sort(a, a+na);
		sort(b, b+nb);
		sort(c, c+nc);
 
		sa = sc = res = 0;
		for (int i = 0, j = 0, k = 0; j < nb; j++){
			while (i < na && a[i] <= b[j])
				sa = (sa + a[i++]) % MOD;
			while (k < nc && c[k] <= b[j])
				sc = (sc + c[k++]) % MOD;
			res = (res + getSum(sa, b[j], sc, i, k)) % MOD;
		}
		cout << res << "\n";
	}
 
	return 0;
} 