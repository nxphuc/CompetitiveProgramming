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

#define pll pair<ll,ll>

struct Node{
	ll l, r;

	Node(ll l = 0, ll r = 0) : l(l), r(r) {}

	bool operator<(const Node& n) const{
		ll x = min(l, r);
		ll y = min(n.l, n.r);
		if (x != y)
			return x > y;
		x = max(l, r);
		y = max(n.l, n.r);
		return x > y;
	}
};

Node makeNode(ll n){
	if (n & 1)
		return Node(n/2, n/2);
	else
		return Node(n/2-1, n/2);
}

pll solve(ll n, ll k){
	map<Node, ll> mymap;
	Node tmp;
	ll cnt;
	mymap[makeNode(n)] = 1;
	while (!mymap.empty()){
		tmp = mymap.begin()->first;
		cnt = mymap.begin()->second;
		mymap.erase(mymap.begin());
		k -= cnt;
		if (k <= 0)
			return mp(max(tmp.l, tmp.r), min(tmp.l, tmp.r));
		mymap[makeNode(tmp.l)] += cnt;
		mymap[makeNode(tmp.r)] += cnt;
	}
}

int main(){
	freopen("C-large.in", "rt", stdin);
	freopen("C-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int T;
	ll n, k;

	cin >> T;
	FOR(cs,1,T){
		cin >> n >> k;
		pll res = solve(n, k);
		cout << "Case #" << cs << ": " << res.fi << " " << res.se << "\n";
	}

	return 0;
}