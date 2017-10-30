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

struct Ring{
	int a, b;
	ll h;

	Ring(int a = 0, int b = 0, ll h = 0) : a(a), b(b), h(h) {}

	bool operator<(const Ring& r) const{
		if (a != r.a)
			return a < r.a;
		if (b != r.b)
			return b < r.b;
		return h < r.h;
	}
};

int n, m;
Ring a[MAX];
map<int, pair<int,ll> > lst;
ll f[MAX];

void reorder(){
	vi b;
	for (map<int, pair<int,ll> >::iterator it = lst.begin(); it != lst.end(); it++){
		a[m].b = it->fi;
		a[m].a = (it->se).fi;
		a[m].h = (it->se).se;
		b.pb(a[m].a);
		b.pb(a[m].b);
		m++;
	}

	map<int,int> id;
	sort(b.begin(), b.end());
	n = 0;
	for (int i = 0; i < b.size(); i++)
		if (!i || b[i] != b[i-1])
			id[b[i]] = ++n;

	REP(i,0,m){
		a[i].a = id[a[i].a];
		a[i].b = id[a[i].b];
	}
}

ll getMax(int id, int l, int r, int lo, int hi){
	if (hi < l || r < lo)
		return -inf;
	if (lo <= l && r <= hi)
		return f[id];
	int m = (l + r)/2;
	ll x = getMax(id*2, l, m, lo, hi);
	ll y = getMax(id*2+1, m+1, r, lo, hi);
	return max(x, y);
}

void update(int id, int l, int r, int pos, ll val){
	if (l == r && l == pos){
		f[id] = max(f[id], val);
		return;
	}
	int m = (l + r)/2;
	if (pos <= m)
		update(id*2, l, m, pos, val);
	else
		update(id*2+1, m+1, r, pos, val);
	f[id] = max(f[id*2], f[id*2+1]);
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	REP(i,0,n){
		int x, y, h;
		cin >> x >> y >> h;
		if (lst.count(y)){
			x = min(x, lst[y].fi);
			h += lst[y].se;
		}
		lst[y] = mp(x, h);
	}

	reorder();

	// REP(i,0,m){
	// 	cout << a[i].a << " " << a[i].b << " " << a[i].h << "\n";
	// }
	ll res = 0;
	REP(i,0,m){
		ll val = getMax(1, 1, n, a[i].a, a[i].b);
		res = max(res, val+a[i].h);
		update(1, 1, n, a[i].b, val+a[i].h);
	}
	cout << res;

	return 0;
}