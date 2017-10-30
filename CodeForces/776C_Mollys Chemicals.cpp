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

ll a[MAX];
int n, k;

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int flag = 0;

	cin >> n >> k;
	FOR(i,1,n){
		cin >> a[i];
		a[i] += a[i-1];
	}

	ll res = 0;
	ll lim = 1e16;

	if (k == 1){
		map<ll,ll> lst;
		FOR(i,0,n){
			if (lst.count(a[i] - 1))
				res += lst[a[i] - 1];
			lst[a[i]]++;
		}

		cout << res;
		return 0;
	}
	if (k == -1){
		map<ll,ll> lst;
		FOR(i,0,n){
			if (lst.count(a[i] - 1))
				res += lst[a[i] - 1];
			lst[a[i]]++;
		}

		lst.clear();
		FOR(i,0,n){
			if (lst.count(a[i] + 1))
				res += lst[a[i] + 1];
			lst[a[i]]++;
		}
		cout << res;
		return 0;
	}

	for (ll p = 1; p <= lim; p *= k){
		map<ll,ll> lst;
		FOR(i,0,n){
			if (lst.count(a[i] - p))
				res += lst[a[i] - p];
			lst[a[i]]++;
		}
	}

	cout << res;

	return 0;
}