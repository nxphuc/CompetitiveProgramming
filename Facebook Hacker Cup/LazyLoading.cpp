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

int n, a[110];

int process(){
	int res = 0;
	int l = 0, r = n-1;

	sort(a,a+n);
	while (r >= 0 && a[r] >= 50)
		res++, r--;
	while (r >= l){
		if (49/a[r] + 1 > (r-l+1))
			break;
		l += 49/a[r];
		r--;
		res++;
	}
	return res;
}

int main(){
	// freopen("lazy_loading.txt", "rt", stdin);
	// freopen("lazy_loading.out", "wt", stdout);
	ios::sync_with_stdio(false);

	int t;

	cin >> t;
	FOR(cs,1,t){
		cin >> n;
		REP(i,0,n) cin >> a[i];
		cout << "Case #" << cs << ": " << process() << "\n";
	}

	return 0;
}