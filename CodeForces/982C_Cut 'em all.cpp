#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

vector<int> adj[MAX];
int n, res = 0;

int dfs(int u, int p) {
    int cnt = 1;
    for (int v : adj[u]) {
        if (v != p) {
            int tmp = dfs(v, u);
            if (tmp % 2 == 0) {
                res += 1;
            }
            cnt += tmp;
        }
    }
    return cnt;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << ((n & 1) ? -1 : res);

    return 0;
}