#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

vector<int> adj[MAX];
int deg[MAX];
vector<int> temp[MAX];
int vis[MAX];

void doTestCase() {
    int n, u, v;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        temp[i].clear();
        deg[i] = 0;
        vis[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if ((n - 1) % 3 != 0) {
        cout << "NO\n";
        return;
    }

    queue<int> q;
    vector<vector<int>> res;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }

    int flag = 1;

    while (!q.empty()) {
        u = q.front();
        q.pop();

        if (vis[u]) {
            continue;
        }
        vis[u] = 1;

        v = -1;
        for (int i = 0; i < adj[u].size(); i++) {
            if (!vis[adj[u][i]]) {
                v = adj[u][i];
                break;
            }
        }

        if (v == -1) {
            cout << "NO\n";
            return;
        }

        // cout << u << " " << v << "\n";

        if (temp[u].size() == 2) {
            temp[u].push_back(v);
            temp[u].insert(temp[u].begin(), u);
            res.push_back(temp[u]);
            temp[u].clear();

            deg[v]--;
            if (deg[v] == 0) {
                vis[v] = 1;
            }
            if (deg[v] == 1) {
                q.push(v);
            }

            continue;
        }
        
        if (temp[u].size() == 0) {
            temp[v].push_back(u);

            if (temp[v].size() == 3) {
                temp[v].insert(temp[v].begin(), v);
                res.push_back(temp[v]);
                temp[v].clear();
            }

            deg[v]--;
            if (deg[v] == 0) {
                vis[v] = 1;
            }
            if (deg[v] == 1) {
                q.push(v);
            }
            continue;
        }
        flag = 0;
        break;
    }

    if (!flag) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (auto tmp : res) {
            for (auto x : tmp) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        doTestCase();
    }

    return 0;
}