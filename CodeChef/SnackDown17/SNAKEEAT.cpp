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

int t, n, q, k;
int a[MAX];
ll f[MAX];

int process(){
	int m, r, l = 0;
	int nn;
	int res = n;
	ll need;

	nn = lower_bound(a, a+n, k) - a;
	if (!nn)
		return n;
	res = nn--;
	r = nn;

	while (l <= r){
		m = (l + r)/2;
		need = f[nn] - (f[m] + 1LL*m*(a[nn] - a[m])) + 1LL*(nn-m+1)*(k - a[nn]);
		if (need <= m){
			res = m;
			r = m-1;
		}
		else
			l = m+1;
	}
	return n - res;
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> q;
		REP(i,0,n)
			cin >> a[i];
		sort(a,a+n);

		f[0] = 0;
		REP(i,1,n)
			f[i] = f[i-1] + 1LL*(a[i] - a[i-1])*i;
		while (q--){
			cin >> k;
			cout << process() << "\n";
		}
	}

	return 0;
}