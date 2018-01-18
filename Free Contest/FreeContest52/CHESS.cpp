#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

int vis[MAX][MAX];
pair<int,int> prv[MAX][MAX];
int t, xa, xb, ya, yb;
char cha, chb;
vector< pair<int,int> > path;
int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, -1, 1};

int inBoard(int x, int y){
	return 0 < x && x < 9 && 0 < y && y < 9;
}

void bfs(){
	int u, v, x, y;
	queue< pair<int,int> > q;

	q.push(make_pair(xa, ya));
	vis[xa][ya] = 0;
	while (!q.empty()){
		u = q.front().first;
		v = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++){
			x = u, y = v;
			do{
				x += dx[i];
				y += dy[i];
				if (!inBoard(x, y)) break;
				if (vis[x][y] == -1){
					vis[x][y] = vis[u][v] + 1;
					prv[x][y] = make_pair(u, v);
					q.push(make_pair(x, y));
				} 
			} while (1);
		}
	}
}

void tracePath(){
	path.clear();
	int x = xb, y = yb;
	pair<int,int> tmp;
	while (x != xa || y != ya){
		path.push_back(make_pair(x, y));
		tmp = prv[x][y];
		x = tmp.first, y = tmp.second;
	}
	path.push_back(make_pair(x, y));
	reverse(path.begin(), path.end());
}

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> cha >> ya >> chb >> yb;
		xa = cha - 'A' + 1;
		xb = chb - 'A' + 1;
		memset(vis, -1, sizeof(vis));
		bfs();
		if (vis[xb][yb] == -1 || vis[xb][yb] > 4)
			cout << "Impossible\n";
		else{
			tracePath();
			cout << path.size()-1;
			for (auto e : path)
				cout << " " << char(e.first + 'A' - 1) << " " << e.second;
			cout << "\n";
		}
	}

	return 0;
}