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

int n;
int a[MAX], b[MAX];
int IT[MAX];
int f[MAX];

void buildTree(int id, int l, int r){
	if (l == r){
		IT[id] = 0;
		return;
	}
	int m = (l+r) >> 1;
	buildTree(id*2+1, l, m);
	buildTree(id*2+2, m+1, r);
	IT[id] = max(IT[2*id+1], IT[2*id+2]);
}

void update(int id, int pos, int val, int l, int r){
	if (pos < l || r < pos)
		return;
	if (l == r){
		IT[id] = max(IT[id], val);
		return;
	}
	int m = (l+r) >> 1;
	update(id*2+1, pos, val, l, m);
	update(id*2+2, pos, val, m+1, r);
	IT[id] = max(IT[id*2+1], IT[id*2+2]);
}

int getMax(int id, int lo, int hi, int l, int r){
	if (lo > hi)
		return 0;
	if (hi < l || r < lo)
		return 0;
	if (lo <= l && r <= hi)
		return IT[id];
	int m = (l + r) >> 1;
	return max(getMax(id*2+1, lo, hi, l, m), getMax(id*2+2, lo, hi, m+1, r));
}

int main(){
	// freopen("test.in", "rt", stdin);
	freopen("nocross.in", "rt", stdin);
	freopen("nocross.out", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> n;
	FOR(i,1,n) cin >> a[i];
	FOR(i,1,n){
		int x;
		cin >> x;
		b[x] = i;
	}

	buildTree(0, 1, n);
	FOR(i,1,n){
		vii lst;
		FOR(j,max(1,a[i]-4),min(n,a[i]+4))
			lst.pb(mp(b[j], getMax(0, 1, b[j]-1, 1, n) + 1));
		REP(j,0,lst.size())
			update(0, lst[j].fi, lst[j].se, 1, n);
	}
	cout << getMax(0, 1, n, 1, n);

	return 0;
}