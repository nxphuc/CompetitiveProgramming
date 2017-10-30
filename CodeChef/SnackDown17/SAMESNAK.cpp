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

ii a[2][2];
int t, flag1, flag2, flag;

int isInSegment(ii p, ii s[2]){
	if (p.fi == s[0].fi && p.fi == s[1].fi)
		return s[0].se <= p.se && p.se <= s[1].se;
	if (p.se == s[0].se && p.se == s[1].se)
		return s[0].fi <= p.fi && p.fi <= s[1].fi;
	return 0;
}

int inSameLine(){
	int flag = 1;
	REP(i,0,2)
		REP(j,0,2)
			flag &= a[i][j].fi == a[0][0].fi;
	if (flag)
		return 1;
	flag = 1;
	REP(i,0,2)
		REP(j,0,2)
			flag &= a[i][j].se == a[0][0].se;
	return flag;
}

int isInRange(){
	return inSameLine() && (isInSegment(a[0][0], a[1]) || isInSegment(a[0][1], a[1]) 
			|| isInSegment(a[1][0], a[0]) || isInSegment(a[1][1], a[0]));
}

int isTouch(){
	REP(i,0,2)
		REP(j,0,2)
			if (a[0][i] == a[1][j])
				return 1;
	return 0;
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		REP(i,0,2){
			REP(j,0,2)
				cin >> a[i][j].fi >> a[i][j].se;
			if (a[i][0] > a[i][1])
				swap(a[i][0], a[i][1]);
		}
		flag1 = (a[0][0].fi == a[0][1].fi) | ((a[0][0].se == a[0][1].se) << 1);
		flag2 = (a[1][0].fi == a[1][1].fi) | ((a[1][0].se == a[1][1].se) << 1);
		flag = 0;
		if (flag1 == 3)
			flag = isInSegment(a[0][0], a[1]);
		else
			if (flag2 == 3)
				flag = isInSegment(a[1][0], a[0]);
			else
				if (flag1 == flag2)
					flag = isInRange();
				else
					flag = isTouch();
		cout << (flag ? "yes\n" : "no\n");
	}

	return 0;
}