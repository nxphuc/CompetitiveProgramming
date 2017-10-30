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

const int MAX = 1e3 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int f[3][MAX];
int n, mn;
int a[26], b[26];
string s;

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	REP(i,0,26) cin >> a[i];
	f[0][0] = 1;
	FOR(i,1,n)
		f[2][i] = inf;

	for (int i = 1; i <= n; i++){
		memset(b,0,sizeof(b));
		mn = inf;
		for (int j = i; j > 0; j--){
			int ch = s[j-1] - 'a';
			if (!b[ch]){
				b[ch] = 1;
				mn = min(mn, a[ch]);
			}
			if (mn < i-j+1) break;
			f[0][i] = (f[0][i] + f[0][j-1]) % MOD;
			f[1][i] = max(f[1][i], max(i-j+1, f[1][j-1]));
			f[2][i] = min(f[2][i], f[2][j-1] + 1);
		}
	}

	REP(i,0,3)
		cout << f[i][n] << "\n";

	return 0;
}