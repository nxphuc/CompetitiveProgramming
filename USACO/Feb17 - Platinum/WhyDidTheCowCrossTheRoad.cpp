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

int n;
ll res, num;
int p[MAX], a[MAX], b[MAX];
int f[MAX];

void setBIT(int id, int val){
	while (id < MAX){
		f[id] += val;
		id += id & -id;
	}
}

int getBIT(int id){
	int ret = 0;
	while (id){
		ret += f[id];
		id -= id & -id;
	}
	return ret;
}

int main(){
	// freopen("test.in", "rt", stdin);
	freopen("mincross.in", "rt", stdin);
	freopen("mincross.out", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> n;
	FOR(i,1,n)
		cin >> a[i];
	FOR(i,1,n)
		cin >> b[i];

	FOR(i,1,n)
		p[a[i]] = i;
	FOR(i,1,n){
		num += i - 1 - getBIT(p[b[i]]-1);
		setBIT(p[b[i]], 1);
	}
	res = num;
	FOR(i,1,n){
		num -= p[b[i]] - 1;
		num += n - p[b[i]];
		res = min(res, num);
	}

	memset(f,0,sizeof(f));
	num = 0;
	FOR(i,1,n)
		p[b[i]] = i;
	FOR(i,1,n){
		num += i - 1 - getBIT(p[a[i]]-1);
		setBIT(p[a[i]], 1);
	}
	res = min(res, num);
	FOR(i,1,n){
		num -= p[a[i]] - 1;
		num += n - p[a[i]];
		res = min(res, num);
	}
	cout << res;

	return 0;
}