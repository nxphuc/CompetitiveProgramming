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

const int MAX = 310;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

ll a[MAX], b[MAX], c[3];
int n, m, t, res;
ll e, dist;

int findMatch(ll dist){
	int i = 0, j = 0;
	int res = 0;

	while (i < n && j < m){
		if (abs(a[i] + dist - b[j]) <= e){
			res++;
			i++;
			j++;
		}
		else
			if (a[i] + dist - b[j] > e)
				j++;
			else
				i++;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> m >> e;
		REP(i,0,n) cin >> a[i];
		REP(i,0,m) cin >> b[i];
		sort(a, a+n);
		sort(b, b+m);
		res = findMatch(0);
		c[0] = -e; c[1] = 0; c[2] = e;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int k = 0; k < 3; k++){
					dist = b[j] + c[k] - a[i];
					res = max(res, findMatch(dist));
				}
		cout << res << "\n";
	}

	return 0;
}