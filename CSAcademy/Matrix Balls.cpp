#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 510;
const int MOD = 1e9 + 7;
const int INF = 1e9;

struct Point {
    int value, x, y;

    Point(int value = 0, int x = 0, int y = 0) : value(value), x(x), y(y) {}

    bool operator<(const Point& other) const {
        return value < other.value;
    }
};


int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<pair<int,int>> graph[MAX][MAX];
int n, m;
int a[MAX][MAX];
int visited[MAX][MAX];
vector<Point> list_points;
int f[MAX][MAX];

int inBoard(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int bfs(int x, int y) {
    queue<pair<int,int>> q;

    q.push(make_pair(x, y));
    visited[x][y] = 1;
    int cnt = 0;
    
    pair<int,int> tmp;
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        cnt++;
        for (auto neighbor: graph[tmp.first][tmp.second]) {
            if (!visited[neighbor.first][neighbor.second]) {
                visited[neighbor.first][neighbor.second] = 1;
                q.push(neighbor);
            }
        }
    }
    return cnt;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int min_value = INF, min_x = -1, min_y = -1;
            for (int x, y, k = 0; k < 8; k++) {
                x = i + dx[k];
                y = j + dy[k];
                if (inBoard(x, y, n, m) && min_value > a[x][y]) {
                    min_x = x, min_y = y, min_value = a[x][y];
                }
            }
            if (min_value < a[i][j]) {
                graph[min_x][min_y].push_back(make_pair(i, j));
            }
            list_points.push_back(Point(a[i][j], i, j));
        }
    }
    sort(list_points.begin(), list_points.end());
    for (const auto& point : list_points) {
        if (visited[point.x][point.y]) {
            f[point.x][point.y] = 0;
        }
        else {
            f[point.x][point.y] = bfs(point.x, point.y);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}