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

const int MAX = 1e5 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int t, n, m;
int a[MAX];
ii b[MAX];

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
		REP(i,0,n) cin >> a[i];
		cin >> m;
		REP(i,0,m)
			cin >> b[i].fi >> b[i].se;

		sort(a,a+n);
		sort(b,b+m);
		int i = 0, j = 0;
		int cnt = 0;
		while (i < n && j < m){
			if (a[i] < b[j].fi)
				i++;
			else
				if (b[j].fi <= a[i] && a[i] <= b[j].se)
					cnt++, i++;
				else
					j++;
		}

		cout << cnt << "\n";
	}

	return 0;
}