// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// const int MAX = 1e3 + 10;
// const double eps = 1e-9;
// const double pi = acos(-1.0);

// struct Circle{
// 	int x, y;
// 	ll r;

// 	Circle(int x = 0, int y = 0, ll r = 0) : x(x), y(y), r(r) {}
// };

// Circle c[MAX];
// vector<int> graph[MAX];
// vector<int> child[MAX];
// vector<int> topo;
// int visited[MAX];
// ll f[MAX], res;
// int n;

// void topoSort(int u){
// 	visited[u] = 1;
// 	for (auto v: graph[u])
// 		if (!visited[v])
// 			topoSort(v);
// 	topo.push_back(u);
// }

// ll dist(int x1, int y1, int x2, int y2){
// 	return sqrt(1LL*(x1-x2)*(x1-x2) + 1LL*(y1-y2)*(y1-y2));
// }

// int contain(int u, int v){
// 	if (c[u].r <= c[v].r)
// 		return 0;
// 	return (c[u].r - c[v].r)*(c[u].r - c[v].r) - dist(c[u].x, c[u].y, c[v].x, c[v].y) >= 0;
// }

// ll dfs(int u){
// 	ll res = c[u].r*c[u].r;
// 	for (int v : child[u])
// 		res -= dfs(v);
// 	return f[u] = res;
// }

// int main(){
// 	#ifndef ONLINE_JUDGE
// 		freopen("test.in", "rt", stdin);
// 	#endif
// 	ios::sync_with_stdio(false);

// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 		cin >> c[i].x >> c[i].y >> c[i].r;
// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < n; j++)
// 			if (contain(i, j))
// 				graph[i].push_back(j);
// 	for (int i = 0; i < n; i++)
// 		if (!visited[i])
// 			topoSort(i);
// 	memset(visited, false, sizeof(visited));
// 	for (int u, i = 0; i < n; i++){
// 		u = topo[i];
// 		for (int v : graph[u])
// 			if (!visited[v]){
// 				child[u].push_back(v);
// 				visited[v] = 1;
// 			}
// 	}
// 	for (int i = 0; i < n; i++){
// 		cout << "# " << i << ": ";
// 		for (int v : child[i])
// 			cout << v << " ";
// 		cout << "\n";
// 	}
// 	memset(f, -1, sizeof(f));
// 	reverse(topo.begin(), topo.end());
// 	for (int u : topo)
// 		if (f[u] == -1)
// 			res += dfs(u);
// 	cout << res << "\n";
// 	cout << fixed << setprecision(10) << pi*res;

// 	return 0;
// }