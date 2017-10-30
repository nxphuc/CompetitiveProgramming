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

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	int n;
	int a[51][51];
	int flag;

	cin >> n;
	REP(i,0,n)
		REP(j,0,n)
			cin >> a[i][j];
	REP(i,0,n)
		REP(j,0,n)
			if (a[i][j] > 1){
			flag = 0;
			REP(x,0,n)
				REP(y,0,n)
					if (x != i && y != j)
						if (a[i][y] + a[x][j] == a[i][j]){
							flag = 1;
							break;
						}
			if (!flag){
				cout << "NO";
				return 0;
			}
		}
	cout << "YES";

	return 0;
}