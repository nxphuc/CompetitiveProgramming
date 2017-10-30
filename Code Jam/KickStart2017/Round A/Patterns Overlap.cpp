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

const int MAX = 2e3 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

char s[MAX], t[MAX];
int f[MAX][MAX];

int dp(int x, int y){
	if (f[x][y] != -1)
		return f[x][y];
	if (!x){
		int yy = y;
		while (yy && t[yy] == '*') yy--;
		return f[x][y] = !yy;
	}
	if (!y){
		int xx = x;
		while (xx && s[xx] == '*') xx--;
		return f[x][y] = !xx;
	}
	if (s[x] == '*'){
		int i = 0;
		int cnt = 0;
		while (cnt <= 4 && i <= y){
			if (cnt <= 4 && dp(x-1, y-i))
				return f[x][y] = 1;
			if (t[y-i] != '*') cnt++;
			i++;
		}
		// for (int i = 0; i <= 4 && i <= y; i++)
		// 	if (dp(x-1, y-i))
		// 		return f[x][y] = 1;
	}
	if (t[y] == '*'){
		int i = 0;
		int cnt = 0;
		while (cnt <= 4 && i <= x){
			if (cnt <= 4 && dp(x-i, y-1))
				return f[x][y] = 1;
			if (s[x-i] != '*') cnt++;
			i++;
		}
		// for (int i = 0; i <= 4 && i <= x; i++)
		// 	if (dp(x-i, y-1))
		// 		return f[x][y] = 1;
	}
	return f[x][y] = (s[x] == t[y] && dp(x-1, y-1));
}

int main(){
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int T, n, m;

	cin >> T;
	FOR(cs,1,T){
		cin >> (s+1) >> (t+1);

		n = strlen(s+1);
		m = strlen(t+1);

		FOR(i,0,n)
			FOR(j,0,m)
				f[i][j] = -1;
		f[0][0] = 1;

		cout << "Case #" << cs << ": " << (dp(n, m) ? "TRUE\n" : "FALSE\n");
	}

	return 0;
}