#include <bits/stdc++.h>
using namespace std;

int a[15][15];
int visited[15][15];
int n, m, u, v, cs, res;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int inBoard(int x, int y){
	return 0 <= x && x < 10 && 0 <= y && y < 10;
}

void findPath(int u, int v, int cnt){
	int x, y;

	visited[u][v] = 1;
	for (int i = 0; i < 8; i++){
		x = u + dx[i];
		y = v + dy[i];
		if (inBoard(x, y) && a[x][y] == 1 && !visited[x][y])
			findPath(x, y, cnt+1);
	}
	res = max(res, cnt);
	visited[u][v] = 0;
}

int findPath2(int u, int v){
	int x, y;
	int res = 0;

	visited[u][v] = 1;
	for (int i = 0; i < 8; i++){
		x = u + dx[i];
		y = v + dy[i];
		if (inBoard(x, y) && a[x][y] == 1 && !visited[x][y])
			res = max(res, findPath2(x, y));
	}
	visited[u][v] = 0;
	return res+1;
}

int main(){
	ios::sync_with_stdio(false);

	while (cin >> n, n){
		memset(a,0,sizeof(a));
		m = 0;
		cs++;

		for (int i = 0; i < n; i++){
			cin >> u >> v;
			for (int j = 0; j < v; j++)
				a[i][u + j] = 1;
			m += v;	
		}

		/* Cach 1: */
		// res = 0;
		// findPath(0,0,1);

		/* Cach 2: */
		res = findPath2(0,0);


		cout << "Case " << cs << ", " << m - res << " ";
		if (m - res == 1)
			cout << "square can not be reached.\n";
		else
			cout << "squares can not be reached.\n";
	}
	
	return 0;
}