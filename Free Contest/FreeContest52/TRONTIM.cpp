#include <bits/stdc++.h>
using namespace std;

const int MAX = 110;
const int INF = 1e9;

char a[MAX][MAX];
int f[3][MAX][MAX];
vector< pair<int,int> > des;
int n, m, k;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int inBoard(int x, int y){
	return 0 <= x && x <= n+1 && 0 <= y && y <= m+1;
}

int getValue(char ch){
	return ch == '#';
}

void dijkstra(int sx, int sy, int f[MAX][MAX]){
	priority_queue< pair<int, pair<int,int> >,
					vector< pair<int, pair<int,int> > >,
					greater< pair<int, pair<int,int> > > > pq;
	int x, y, w, u, v;
	pair<int, pair<int,int> > tmp;
	
	for (int i = 0; i <= n+1; i++)
		for (int j = 0; j <= m+1; j++)
			f[i][j] = INF;
	pq.push(make_pair(0, make_pair(sx, sy)));
	f[sx][sy] = 0;
	while (!pq.empty()){
		tmp = pq.top();
		pq.pop();
		w = tmp.first;
		u = tmp.second.first;
		v = tmp.second.second;

		if (f[u][v] != w) continue;
		for (int i = 0; i < 4; i++){
			x = u + dx[i];
			y = v + dy[i];
			if (inBoard(x, y) && a[x][y] != '*' && f[x][y] > getValue(a[x][y]) + w){
				f[x][y] = getValue(a[x][y]) + w;
				pq.push(make_pair(f[x][y], make_pair(x, y)));
			}
		}
	}
}

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	memset(a, '.', sizeof(a));
	des.push_back(make_pair(0, 0));

	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> (a[i]+1);
		for (int j = 1; j <= m; j++)
			if (a[i][j] == '$')
				des.push_back(make_pair(i,j));
	}
	assert(des.size() == 3);

	for (int i = 0; i < 3; i++)
		dijkstra(des[i].first, des[i].second, f[i]);
	int res = INF;
   	for (int i = 0; i <= n+1; i++)
   		for (int j = 0; j <= m+1; j++)
   			if (a[i][j] != '*')
   				res = min(res, f[0][i][j] + f[1][i][j] + f[2][i][j] - 2*getValue(a[i][j]));
	cout << res;

	return 0;
}