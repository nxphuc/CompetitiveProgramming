void dfs(int u) {
    for (pair<int, int> v : b[u]) {
        if (vis[v.first] == -1) {
            vis[v.first] = vis[u] ^ v.second;
            dfs(v.first);
        }
        else {
            if (vis[v.first] != vis[u] ^ v.second) {
                cout << "NO";
                exit(0);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int x;
            cin >> x;
            x--;
            d[x].pb(i);
        }
    }   
    for (int i = 0; i < n; i++) {
        int u = d[i][0], v = d[i][1];
        b[u].pb({v, a[i] ^ 1});
        b[v].pb({u, a[i] ^ 1});
    }
    for (int i = 0; i < m; i++) {
        vis[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        if (vis[i] == -1) {
            vis[i] = 0;
            dfs(i);
        }
    }
    cout << "YES";
    return 0;
}