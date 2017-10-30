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

set< ii > res;
set< pair<ii, int> > f[35];
set< pair<ii, int> >::iterator it;
int n;
int t[100];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(){
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	REP(i,0,n)
		cin >> t[i];
	f[0].insert(mp(mp(0, 0), 0));
	REP(i,0,n){
		for (it = f[i].begin(); it != f[i].end(); it++){
			int x = (it->fi).fi;
			int y = (it->fi).se;
			int dir = it->se;
			REP(j,0,t[i]){
				// cout << x + dx[dir]*j << " " << y + dy[dir]*j << "\n";
				res.insert(mp(x + dx[dir]*j, y + dy[dir]*j));
			}
			x += dx[dir]*(t[i]-1);
			y += dy[dir]*(t[i]-1);

			int nx = x + dx[(dir + 7) % 8];
			int ny = y + dy[(dir + 7) % 8];
			f[i+1].insert(mp(mp(nx, ny), (dir + 7) % 8));

			nx = x + dx[(dir + 1) % 8];
			ny = y + dy[(dir + 1) % 8];
			f[i+1].insert(mp(mp(nx, ny), (dir + 1) % 8));
		}
	}

	cout << res.size();
	// for (set<ii>::iterator itr = res.begin(); itr != res.end(); itr++)
	// 	cout << itr->fi << " " << itr->se << "\n";

	return 0;
}