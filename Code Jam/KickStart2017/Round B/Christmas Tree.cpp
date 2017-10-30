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

const int MAX = 110;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int mark[MAX][MAX];
int f[MAX][MAX][MAX];
char a[MAX][MAX];
int t, n, m, k;

void process(int x, int y){
	for (int k = 0; x+k <= n; k++){
		for (int i = 0; i <= k; i++){
			if (y-i < 1 || a[x+k][y-i] != '#')
				return;
			if (y+i > m || a[x+k][y+i] != '#')
				return;
		}
		mark[x+k][y-k] = max(mark[x+k][y-k], k);
	}
}

void solveDP(){
	memset(f,-1,sizeof(f));
	FOR(x,1,n)
		FOR(y,1,m){
			int h = mark[x][y];
			for (int k = 0; k <= h; k++)
				f[1][x-k][y+k] = max(f[1][x-k][y+k], (k+1)*(k+1));
		}
	for (int kk = 2; kk <= k; kk++){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (f[kk-1][i][j] != -1){
					int x = i-1;
					if (!x) break;
					for (int y = 1; y <= j; y++){
						int mn = (j - y + 1)/2;
						for (int h = mn; h <= mark[x][y]; h++){
							if (k - kk > x-h-1) break;
							f[kk][x-h][y+h] = max(f[kk][x-h][y+h], f[kk-1][i][j] + (h+1)*(h+1));
						}
					}
				}
	}
}

int main(){
	freopen("C-large.in", "rt", stdin);
	freopen("C-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	FOR(cs,1,t){
		cerr << "Case " << cs << ": ";
		cin >> n >> m >> k;

		memset(mark, -1, sizeof(mark));
		FOR(i,1,n)
			cin >> (a[i]+1);

		FOR(i,1,n)
			FOR(j,1,m)
				if (a[i][j] == '#')
					process(i,j);

		solveDP();
		int res = 0;
		FOR(i,1,n)
			FOR(j,1,m)
				res = max(res, f[k][i][j]);
		cout << "Case #" << cs << ": " << res << "\n";
		cerr << "Done!\n";
		// FOR(kk,1,k){
		// 	FOR(i,1,n){
		// 		FOR(j,1,m)
		// 			cout << f[kk][i][j] << " ";
		// 		cout << "\n";
		// 	}
		// 	cout << "---\n";
		// }
		// cout << "\n\n";
	}

	return 0;
}