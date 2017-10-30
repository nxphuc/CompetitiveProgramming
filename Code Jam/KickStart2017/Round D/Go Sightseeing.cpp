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

const int MAX = 2e3 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int t, n;
ll ts, tf;
ll s[MAX], f[MAX], d[MAX];
ll dp[MAX][MAX];

inline ll nextTime(ll cur, ll beg, ll cyc){
	if (cur <= beg)
		return beg;
	return beg+((cur - beg - 1)/cyc + 1)*cyc;
}

int doTestCase(){
	ll nxtTime;
	dp[1][0] = 0;
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			nxtTime = nextTime(dp[i][j], s[i], f[i]) + d[i];
			if (dp[i+1][j] == -1 || dp[i+1][j] > nxtTime)
				dp[i+1][j] = nxtTime;
			nxtTime = nextTime(dp[i][j] + ts, s[i], f[i]) + d[i];
			if (dp[i+1][j+1] == -1 || dp[i+1][j+1] > nxtTime)
				dp[i+1][j+1] = nxtTime;
		}
	}
	for (int i = n-1; i >= 0; i--)
		if (dp[n][i] <= tf)
			return i;
	return -1;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("A-large.in", "rt", stdin);
		freopen("A-large.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	cin >> t;
	FOR(cs,1,t){
		memset(dp,-1,sizeof(dp));
		cin >> n >> ts >> tf;
		REP(i,1,n)
			cin >> s[i] >> f[i] >> d[i];
		int res = doTestCase();
		cout << "Case #" << cs << ": ";
		if (res != -1)
			cout << res << "\n";
		else
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}