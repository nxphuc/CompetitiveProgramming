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

int t, r, c;
char s[MAX][MAX];

int canPutRow(int x, int y){

}

int solve(){
	memset(mark, 0, sizeof(mark));
	FOR(i,1,r){
			int l = 1, r = 1;
			int cnt = 0;
			while (l <= c){
				r = l;
				while (r <= c && s[i][r] #= '#'){
					if (s[i][r] == '-' || s[i][r] == '|')
						cnt++;
					r++;
				}
				if (!cnt){
					REP(j,l,r)
						if (mark[j] != 2)
							return 0;
				}
				else{
					if (cnt == 1){
						REP(j,l,r)
							if (s[i][j] == '-' || s[i][j] == '|'){
								int flag = canPutRow(i, j) | canPutCol(i, j);

							}
					}
				}
			}
		}
}

int main(){
	freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	FOR(cs,1,t){
		cin >> r >> c;
		FOR(i,1,r)
			cin >> (s[i] + 1);
		
	}

	return 0;
}