#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define pb push_back

const int MAX = 1e6 + 10;
const int N = 1e2 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0); 
const double eps = 1e-6;

int r[N];
vector<int> v[N];
vector<int> a[N];
bool vis[N];
int flag, mark;
int n, m, ans;

int label(int x)
{
	if (r[x] == 0) return x;
	else return label(r[x]);
}

void merge(int x, int y)
{
	int l1 = label(x);
	int l2 = label(y);
	if (l1 == l2) return;
	if (l1 < l2) r[l2] = l1;
	else r[l1] = l2;
}

void dfs(int x, int len)
{
	if (flag == false) return;
	if (x == mark) {
		ans = max(ans, len + 1);
		return;
	}
	if (vis[x]) {
		flag = false;
		return;
	}
	vis[x] = 1;
	for (auto y : a[x]) {
		dfs(y, len + 1);
	}
}

int solve()
{
	int ret = 1000000000;
	for (int i = 1; i <= n; i++) {
		// mark = v[id][i];
		mark = i;
		flag = 1;
		ans = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				memset(vis, 0, sizeof(vis));
				dfs(v[id][j]);
				if (flag) {
					ret = min(ret, ans);
				}
			}

		}
		memset(vis, 0, sizeof(vis));
		// for (int j = 0; j < v[id].size(); j++) {
		// 	memset(vis, 0, sizeof(vis));
			// dfs(v[id][j], 0);
		// }
		// if (flag) {
		// 	ret = min(ret, ans);
		// }

	}
	if (ret == 1000000000) return -1;
	else return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].pb(y);
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (auto x : a[i]) {
	// 		merge(x, i);
	// 	}
	// }
	// for (int i = 1; i <= n; i++) {
	// 	int l = label(i);
	// 	v[l].pb(i); 
	// }
	int ans = 0;
	// for (int i = 1; i <= n; i++) {
		// if (v[i].size() > 0) { 
		// 	int x = solve(i);
		// 	if (x == -1) {
		// 		cout << -1;
		// 		return 0;
		// 	}
		// 	ans += x;
		// }
	// }
	solve();
	cout << ans << endl;
	return 0;
}