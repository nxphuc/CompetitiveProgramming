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

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n, m;
string s[21];

int dfs(int x, int y){
	stack< pair<int,int> > st;
	int cnt = 1;
	int u, v;

	st.push(mp(x, y));
	s[x][y] = '#';
	while (!st.empty()){
		x = st.top().fi;
		y = st.top().se;
		st.pop();

		REP(i,0,4){
			u = x + dx[i];
			v = y + dy[i];
			if (u >= 0 && u < n && v >= 0 && v < m && s[u][v] == '.'){
				st.push(mp(u,v));
				cnt++;
				s[u][v] = '#';
			}
		}
	}
	return cnt;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, x, y;

	cin >> t;
	FOR(cs,1,t){
		cin >> m >> n;
		REP(i,0,n){
			cin >> s[i];
			REP(j,0,m)
				if (s[i][j] == '@')
					x=i,y=j;
		}
		cout << "Case " << cs << ": " << dfs(x,y) << "\n";
	}

	return 0;
}