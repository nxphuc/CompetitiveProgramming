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

const int MAX = 1e2 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, m, u;
vector< ii > edges;
int f[MAX], ene[MAX];

int canReach(int s, int t){
	queue<int> q;
	vector<bool> visited(n+10, false);

	q.push(s);
	visited[s] = true;
	while (!q.empty()){
		s = q.front();
		q.pop();
		for (ii e : edges)
			if (s == e.first && !visited[e.second]){
				visited[e.second] = true;
				q.push(e.second);
				if (e.second == t)
					return true;
			}
	}
	return false;
}

int main(){
	freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	while (cin >> n, n != -1){
		edges.clear();
		for (int i = 1; i <= n; i++){
			f[i] = -inf;
		}

		for (int i = 1; i <= n; i++){
			cin >> ene[i] >> m;
			while (m--){
				cin >> u;
				edges.push_back(make_pair(i, u));
			}
		}

		f[1] = 100;
		for (int i = 1; i < n; i++){
			for (ii e : edges){
				if (f[e.first] <= 0) continue;
				f[e.second] = max(f[e.second], f[e.first] + ene[e.second]);
			}
		}

		bool cycle = false;
		for (ii e : edges){
			if (f[e.first] <= 0) continue;
			if (f[e.second] < f[e.first] + ene[e.second] && canReach(e.first, n)){
				cycle = true;
				break;
			}
		}

		cout << ((cycle || f[n] > 0) ? "winnable\n" : "hopeless\n");
	}

	return 0;
}