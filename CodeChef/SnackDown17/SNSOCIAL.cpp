#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 510;
 
int t, n, m, mx;
int a[MAX][MAX];
int f[MAX][MAX];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
int inRange(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}
 
int bfs(){
	queue< pair<int,int> > q;
	int res = 0;
	pair<int,int> cur, nxt;
	int u, v, x, y;
 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == mx){
				f[i][j] = 0;
				q.push(make_pair(i,j));
			}
			else
				f[i][j] = -1;
 
	while (!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		res = max(res, f[x][y]);
 
		for (int i = 0; i < 8; i++){
			u = x + dx[i];
			v = y + dy[i];
 
			if (inRange(u, v) && f[u][v] == -1){
				f[u][v] = f[x][y] + 1;
				q.push(make_pair(u, v));
			}
		}
	}
	return res;
}
 
int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);
 
	cin >> t;
	while (t--){
		mx = 0;
 
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				cin >> a[i][j];
				mx = max(mx, a[i][j]);
			}
 
		cout << bfs() << "\n";
	}
 
	return 0;
}