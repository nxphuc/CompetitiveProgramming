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

int BIT[MAX];
int n, m;
pair< ii,ii > b[MAX];
ii a[MAX];
int f[MAX];

int cmp(pair< ii,ii > a, pair< ii,ii > b){
	return a.fi.se < b.fi.se;
}

int main(){
	freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	REP(i,0,n){
		cin >> a[i].fi;
		a[i].se = i;
	}
	REP(i,0,m){
		cin >> b[i].fi.fi >> b[i].fi.se >> b[i].se.fi;
		b[i].se.se = i;
	}
	// sort(a,a+n);
	sort(b,b+m,cmp);
	for (int j = 0, i = 0; i < n; i++){
		setBIT(a[i].fi);
		while (j < m && b[j].fi.se == i){
			f[b[j].se.se] = getBIT()
		}
	}

	return 0;
}