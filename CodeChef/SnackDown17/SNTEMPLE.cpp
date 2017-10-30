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

int a[MAX], maxL[MAX], maxR[MAX];
int n, t;
ll sum, res;

ll calc(ll h){ return h*h; }

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			sum += a[i];
		}

		maxL[0] = maxR[n+1] = 0;
		for (int i = 1; i <= n; i++)
			maxL[i] = min(maxL[i-1] + 1, a[i]);
		for (int i = n; i > 0; i--)
			maxR[i] = min(maxR[i+1] + 1, a[i]);
		
		res = sum;
		for (int i = 1; i <= n; i++)
			res = min(res, sum - calc(min(maxL[i], maxR[i])));
		cout << res << "\n";
	}

	return 0;
}