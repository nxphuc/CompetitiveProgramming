#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	int dx[4] = {-1, 0, 0, 1};
	int dy[4] = {0, -1, 1, 0};

	vector<string> a;
	int n, m, res = 0;

	cin >> n >> m;
	a.resize(n+2);
	a[0] = a[n+1] = string(m+2,'0');
	for (int i = 1; i <= n; i++){
		a[i].assign(m+2, '0');
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
		a[i][0] = a[i][m+1] = '0';
	}
	queue< pair<int,int> > q;
	int u, v, x, y;

	q.push(make_pair(0,0));
	a[0][0] = '#';
	while (!q.empty()){
		u = q.front().first;
		v = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			x = u + dx[i], y = v + dy[i];
			if (x >= 0 && x <= n+1 && y >= 0 && y <= m+1){
				if (a[x][y] == '#') continue;
				if (a[x][y] == '1')
					res++;
				else{
					q.push(make_pair(x, y));
					a[x][y] = '#';
				}
			}
		}
	}
	cout << res;

	return 0;
}