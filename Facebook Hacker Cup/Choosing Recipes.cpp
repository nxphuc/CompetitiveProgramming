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

int t, r, p, n, m;
int x;
int res;
int c[50];
int b[50];
int a[50];

void init(){
	res = inf;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
}

int isValid(int mask){
	int cnt = 0;
	REP(i,0,r)
		cnt += (mask & a[i]) == a[i];
	return cnt >= n;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		init();

		cin >> r >> p >> n >> m;
		REP(i,0,m){
			cin >> x;
			b[x] = 1;
		}
		REP(i,0,p)
			cin >> c[i];
		REP(i,0,r){
			a[i] = 0;
			REP(j,0,p){
				cin >> x;
				a[i] |= x << j;
			}
		}

		int k = 1 << p;
		REP(i,0,k){
			if (isValid(i)){
				int sum = 0;
				REP(j,0,p)
					if (((i >> j) & 1) && !b[j])
						sum += c[j];
				res = min(res, sum);
			}
		}

		cout << res << "\n";
	}

	return 0;
}