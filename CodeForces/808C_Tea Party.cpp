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

int a[MAX], p[MAX], f[MAX];
int n, w, s;

int cmp(int x, int y){
	return a[x] < a[y];
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> n >> w;
	REP(i,0,n){
		cin >> a[i];
		p[i] = i;
	}
	sort(p, p+n, cmp);
	REP(i,0,n){
		f[p[i]] = (a[p[i]] + 1)/2;
		s += f[p[i]];
	}
	for (int i = n-1; i >= 0 && s < w; i--){
		int val = min(a[p[i]] - f[p[i]], w - s);
		s += val;
		f[p[i]] += val;
	}
	if (s != w)
		cout << -1;
	else
		REP(i,0,n)
			cout << f[i] << " ";

	return 0;
}