#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 1e5 + 10;
const ll inf = 1e15;

int t, n, u, v;
vector<int> graph[MAX];
ll p[MAX], c[MAX], f[MAX][2];

ll dfs(int u, int state, int parent){
	if (f[u][state] != -1)
		return f[u][state];
	ll ret = inf;
	ll tmp = p[u];

	for (int v: graph[u])
		if (v != parent){
			tmp += dfs(v, 1, u);
		}
	ret = min(ret, tmp);

	int need = c[u] - state;
	if (graph[u].size() - (parent != -1) >= need){
		tmp = 0;
		vector<ll> seq;
		for (int v: graph[u]){
			if (v != parent){
				tmp += dfs(v, 1, u);
				seq.push_back(dfs(v, 0, u) - dfs(v, 1, u));
			}
		}
		sort(seq.begin(), seq.end());
		for (int i = 0; i < need; i++){
			tmp += seq[i];
		}
		ret = min(ret, tmp);
	}
	return f[u][state] = ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);
	
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) graph[i].clear();
		for (int i = 1; i < n; i++){
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
			cin >> p[i];
		for (int i = 1; i <= n; i++)
			cin >> c[i];
		memset(f,-1,sizeof(f));
		cout << dfs(1, 0, -1) << "\n";
	}

	return 0;
}