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

const int MAX = 1e5 + 2;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll f[3][11][11][11][11][11][11];
ll c[MAX][61];

// r = 0, b = 1, g = 2
ll dp(int lst, int rb, int rg, int br, int bg, int gr, int gb){
	if (rb < 0 || rg < 0 || br < 0 || bg < 0 || gr < 0 || gb < 0)
		return 0;
	if (f[lst][rb][rg][br][bg][gr][gb] != -1)
		return f[lst][rb][rg][br][bg][gr][gb];
	ll &ret = f[lst][rb][rg][br][bg][gr][gb];
	ret = 0;
	switch (lst){
		case 0:
			if (br)
				ret = (ret + dp(1, rb, rg, br-1, bg, gr, gb)) % MOD;
			if (gr)
				ret = (ret + dp(2, rb, rg, br, bg, gr-1, gb)) % MOD;
			break;
		case 1:
			if (rb)
				ret = (ret + dp(0, rb-1, rg, br, bg, gr, gb)) % MOD;
			if (gb)
				ret = (ret + dp(2, rb, rg, br, bg, gr, gb-1)) % MOD;
			break;
		case 2:
			if (rg)
				ret = (ret + dp(0, rb, rg-1, br, bg, gr, gb)) % MOD;
			if (bg)
				ret = (ret + dp(1, rb, rg, br, bg-1, gr, gb)) % MOD;
			break;
	}
	return ret;
}

ll powMod(int b, int p){
	if (!p)
		return 1;
	ll ret = powMod(b, p/2);
	ret = (ret * ret) % MOD;
	if (p & 1)
		ret = (ret * b) % MOD;
	return ret;
}

ll nCk(int n, int k){
	return c[n][k];
	// ll ret = 1;
	// FOR(i,1,n)
	// 	ret = (ret * i) % MOD;
	// FOR(i,1,k)
	// 	ret = (ret * powMod(i, MOD-2)) % MOD;
	// FOR(i,1,n-k)
	// 	ret = (ret * powMod(i, MOD-2)) % MOD;
	// return ret;
}

void prepare(){
	REP(i,0,MAX)
		c[i][0] = 1;
	REP(i,1,MAX){
		int k = min(60, i);
		FOR(j,1,k){
			c[i][j] = c[i-1][j] + c[i-1][j-1];
			if (c[i][j] >= MOD)
				c[i][j] -= MOD;
		}
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	prepare();

	int n, rb, rg, br, bg, gr, gb;

	cin >> n;
	cin >> rb >> rg >> br >> bg >> gr >> gb;

	ll res = 0;

	memset(f, -1, sizeof(f));
	REP(i,0,3)
		f[i][0][0][0][0][0][0] = 1;
	FOR(irb,0,rb)
		FOR(irg,0,rg)
			FOR(ibr,0,br)
				FOR(ibg,0,bg)
					FOR(igr,0,gr)
						FOR(igb,0,gb){
							int s = irb + irg + ibr + ibg + igr + igb;
							if (s >= n)
								continue;
							ll cur = 0;
							REP(i,0,3)
								cur = (cur + dp(i, irb, irg, ibr, ibg, igr, igb)) % MOD;
							cur = (cur * nCk(n-1, s)) % MOD;
							// cout << cur << "\n";
							res = (res + cur) % MOD;
						}
	cout << res << "\n";
	// cout << (res * nCk(n, s)) % MOD;

	return 0;
}