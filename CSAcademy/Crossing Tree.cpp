#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

vector<int> a[MAX];
int n;
int level[MAX];
int parent[MAX];

void dfs(int u, int lvl, int par = -1) {
    level[u] = lvl;
    for (int v : a[u]) {
        if (v != par) {
            parent[v] = u;
            dfs(v, lvl + 1, u);
        }
    }
}

void print(int u, int par, int prev = -1) {
    cout << u << " ";
    for (int v : a[u]) {
        if (v != par && v != prev) {
            print(v, u, u);
            cout << u << " ";
        }
    }
    if (par != prev && par) {
        print(par, parent[par], u);
    }
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 1);
    int start_node = 1;
    for (int i = 1; i <= n; i++) {
        parent[i] = 0;
        if (level[i] > level[start_node]) {
            start_node = i;
        }
    }
    dfs(start_node, 1);
    start_node = 1;
    for (int i = 1; i <= n; i++) {
        if (level[i] > level[start_node]) {
            start_node = i;
        }
    }
    cout << 2*n - level[start_node] - 1 << "\n";
    print(start_node, parent[start_node]);

    return 0;
}