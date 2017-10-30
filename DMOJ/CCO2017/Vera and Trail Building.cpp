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

const int MAX = 5e3 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, m, k;
vector< pair<int,int> > edges;

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> k;
	while (k){
		m = sqrt(2*k) + 10;
		while (m*(m-1)/2 > k) m--;
		for (int i = 0; i < m; i++)
			edges.push_back(make_pair(i+n+1, (i + 1) % m + n + 1));
		if (n)
			edges.push_back(make_pair(1, n+1));
		n += m;
		k -= m*(m-1)/2;
	}

	cout << n << " " << edges.size() << "\n";
	for (int i = 0; i < edges.size(); i++)
		cout << edges[i].first << " " << edges[i].second << "\n";

	return 0;
}