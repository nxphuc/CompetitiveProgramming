#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 210;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

string dn[6] = {"UL", "UR", "R", "LR", "LL", "L"};
int dx[6] = {-2, -2, 0, 2, 2, 0};
int dy[6] = {-1, 1, 2, 1, -1, -2};
int path[MAX][MAX];
int dist[MAX][MAX];
int n;
pair<int, int> source, dest;

void bfs() {
	queue<pair<int, int>> q;
	pair<int, int> tmp;

	dist[source.first][source.second] = 0;
	q.push(source);
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int x = tmp.first + dx[i], y = tmp.second + dy[i];
			if (0 <= x && x < n && 0 <= y && y < n && dist[x][y] == -1) {
				dist[x][y] = dist[tmp.first][tmp.second] + 1;
				path[x][y] = i;
				q.push(make_pair(x, y));
			}
		}
	}
}

void printPath() {
	if (dist[dest.first][dest.second] == -1) {
		cout << "Impossible";
		return;
	}
	cout << dist[dest.first][dest.second] << "\n";
	vector<string> p;
	while (dest.first != source.first || dest.second != source.second) {
		int d = path[dest.first][dest.second];
		p.push_back(dn[d]);
		dest.first -= dx[d];
		dest.second -= dy[d];
	}
	reverse(p.begin(), p.end());
	for (auto a : p) {
		cout << a << " ";
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	memset(path, -1, sizeof(path));
	memset(dist, -1, sizeof(dist));
	cin >> source.first >> source.second >> dest.first >> dest.second;
	bfs();
	printPath();
	
	return 0;
}