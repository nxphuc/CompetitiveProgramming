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

const int MAX = 60;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int a[MAX];
int b[MAX][MAX];
int id[MAX];
int t, n, p;
int res = 0;

int valid(ll x, ll num, ll val){
	ll mn = 90*val*num;
	ll mx = 110*val*num;
	x *= 100;
	if (x < mn) return -1;
	if (x > mx) return 0;
	return 1;
}

int main(){
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	FOR(cs,1,t){
		cin >> n >> p;

		REP(i,0,n) cin >> a[i];
		REP(i,0,n){
			REP(j,0,p) cin >> b[i][j];
			sort(b[i], b[i] + p);
		}
		memset(id,0,sizeof(id));
		res = 0;
		for (int number = 1; number <= MAXN; number++){
			int flag = 1;
			REP(i,0,n){
				while (id[i] < p && valid(b[i][id[i]], number, a[i]) == -1){
					id[i]++;
				}
				if (id[i] >= p){
					flag = 0;
				}
				else{
					flag &= valid(b[i][id[i]], number, a[i]);
				}
			}
			if (flag == 1){
				REP(i,0,n) id[i]++;
				res++;
				number--;
			}
		}

		cout << "Case #" << cs << ": " << res << "\n";
	}

	return 0;
}