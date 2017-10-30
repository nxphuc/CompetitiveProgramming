#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e5 + 10;
 
int parent[MAX];
int id[MAX], ans[MAX];
vector<int> a[MAX];
int t, n, m, Count;
int u, v;
 
int cmp(int x, int y){
	return a[y].size() < a[x].size();
}
 
int findSet(int u){
	return parent[u] = u == parent[u] ? u : findSet(parent[u]);
}
 
int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);
 
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			a[i].clear();
		while (m--){
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)
			parent[i] = id[i] = i;
		sort(id+1,id+n+1,cmp);
 
		int j = 1;
		Count = n-1;
		for (int i = n; i > 0; i--){
			for (; j <= n && a[id[j]].size() == i; j++){
				u = findSet(id[j]);
				for (int e : a[id[j]])
					if (a[e].size() >= i){
						v = findSet(e);
						if (u != v){
							parent[v] = u;
							Count--;
						}
					}
			}
			ans[i-1] = Count;
		}
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
 
	return 0;
} 