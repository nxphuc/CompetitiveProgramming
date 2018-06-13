#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;

vector<int> adj[MAX];
int path[MAX];
int dist[MAX];
int n;

void makeCycle(int s, int t) {
    while (s != t) {
        dist[s] = 0;
        s = path[s];
    }
    dist[t] = 0;
}

int dfs(int s = 1, int p = 0) {
    path[s] = p;
    for (int v: adj[s]) {
        if (v == p) {
            continue;
        }
        if (path[v] != -1) {
            makeCycle(s, v);
            return 1;
        }
        if (dfs(v, s)) {
            return 1;
        }
    }
    return 0;
}

void bfs() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0) {
            q.push(i);
        }
    }
    int u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void doTestCase() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    memset(path, -1, sizeof(path));
    memset(dist, -1, sizeof(dist));

    for (int u, v, i = 0; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();
    bfs();
    for (int i = 1; i <= n; i++) {
        cout << " " << dist[i];
    }
    cout << "\n";
}

int main() {
    freopen("A-large.in", "rt", stdin);
    freopen("A-large.ou", "wt", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ":";
        doTestCase();
    }

    return 0;
}