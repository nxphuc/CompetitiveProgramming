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
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int t, n, m;
	string s[30];

	cin >> t;
	FOR(cs,1,t){
		cin >> n >> m;
		REP(i,0,n) cin >> s[i];
		REP(i,0,n){
			REP(j,0,m)
				if (s[i][j] != '?'){
					char ch = s[i][j];
					int k = j-1;
					while (k >= 0 && s[i][k] == '?')
						s[i][k--] = ch;
					k = j+1;
					while (k < m && s[i][k] == '?')
						s[i][k++] = ch;
				}
		}
		REP(j,0,m){
			REP(i,0,n)
				if (s[i][j] != '?'){
					char ch = s[i][j];
					int k = i-1;
					while (k >= 0 && s[k][j] == '?')
						s[k--][j] = ch;
					k = i+1;
					while (k < n && s[k][j] == '?')
						s[k++][j] = ch;
				}
		}

		cout << "Case #" << cs << ":\n";
		REP(i,0,n) cout << s[i] << "\n";
	}

	return 0;
}