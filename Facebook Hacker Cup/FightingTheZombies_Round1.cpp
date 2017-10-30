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

ii a[60];
map<int, int> listX, listY;
int revX[60], revY[60];
int maxX, maxY;
int f[110][110];
int t, n, R;

void rename(){
	int num = 1;

	for (map<int,int>::iterator it = listX.begin(); it != listX.end(); it++){
		it->se = num++;
		revX[it->se] = it->fi;
	}
	maxX = num;

	num = 1;
	for (map<int,int>::iterator it = listY.begin(); it != listY.end(); it++){
		it->se = num++;
		revY[it->se] = it->fi;
	}
	maxY = num;
}

void prepare(){
	memset(f, 0, sizeof(f));
	REP(i,0,maxX)
		REP(j,0,maxY){
			f[i][j] = 0;
			REP(k,0,n)
				if ((revX[i] - R <= a[k].fi && a[k].fi <= revX[i]) && (revY[j] - R <= a[k].se && a[k].se <= revY[j]))
					f[i][j]++;
		}
}

int solve(){
	int res = -1;
	REP(i,1,maxX)
		REP(j,1,maxY){
			int cnt = 0;
			REP(k,0,n)
				if ((revX[i] <= a[k].fi && a[k].fi <= revX[i] + R) && (revY[j] <= a[k].se && a[k].se <= revY[j] + R))
					cnt++;
			FOR(i2,0,maxX)
				FOR(j2,0,maxY)
					if (i2 < i || j2 < j)
						res = max(res, cnt + f[i2][j2]);
		}
	return res;
}

int main(){
	freopen("fighting_the_zombies.txt", "rt", stdin);
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	freopen("fighting_the_zombies.out", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	FOR(cs,1,t){
		listX.clear();
		listY.clear();

		cin >> n >> R;
		REP(i,0,n){
			cin >> a[i].fi >> a[i].se;
			listX[a[i].fi] = 1;
			listY[a[i].se] = 1;
		}

		rename();
		prepare();
		cout << "Case #" << cs << ": " << solve() << "\n";
	}

	return 0;
}