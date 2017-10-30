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

int n, k;
int a[MAX];
map<int, int> lst;

int solve(int remain, int val){
	if (remain < val)
		return 0;
	if (remain < 2*val)
		return 1;
	if (lst.count(remain))
		return lst[remain];
	if (remain & 1)
		return lst[remain] = solve(remain/2, val) + solve(remain/2+1, val);
	return lst[remain] = 2*solve(remain/2, val);
}

int valid(int val){
	int cnt = 0;
	lst.clear();
	for (int i = 0; i < n; i++){
		cnt += solve(a[i], val);
		if (cnt >= k)
			return 1;
	}
	return cnt >= k;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	REP(i,0,n) cin >> a[i];
	sort(a, a+n, greater<int>());
	int lo = 1, hi = a[0];
	int mi;
	int res = -1;
	while (lo <= hi){
		mi = (lo + hi)/2;
		if (valid(mi)){
			res = mi;
			lo = mi+1;
		}
		else
			hi = mi-1;
	}
	cout << res;

	return 0;
}