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
const int inf = 2e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, k;
ii a[MAX];

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	REP(i,0,n)
		cin >> a[i].fi >> a[i].se;
	sort(a, a+n);

	// REP(i,0,n) cout << a[i].fi << " " << a[i].se << "\n";

	priority_queue<int, vi, greater<int> > pq;
	int res = -1, id = -1;
	REP(i,0,n){
		while (pq.size() > k || (pq.size() && pq.top() < a[i].fi))
			pq.pop();
		if (pq.size() + 1 >= k){
			if (pq.size() == k && pq.top() < a[i].se)
				pq.pop();
			pq.push(a[i].se);
			if (res < pq.top() - a[i].fi + 1){
				res = pq.top() - a[i].fi + 1;
				id = i;
			}
			pq.push(a[i].se);
		}
		else
			pq.push(a[i].se);
	}

	if (id == -1){
		cout << 0 << "\n";
		FOR(i,1,k) cout << i << " ";
		return 0;
	}
	cout << res << "\n";
	cout << id+1;
	k--;
	for (int i = 0; i < id && k; i++)
		if (a[i].se - a[id].fi + 1 >= res){
			cout << " " << i+1;
			k--;
		}

	return 0;
}