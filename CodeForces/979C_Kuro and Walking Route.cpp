#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3e5 + 10;

int n, x, y;
vector<int> a[MAX];
int cnt[MAX];

pair<int, int> dfs(int u, int p) {
    int ret = 1, flag = u == y;
    pair<int, int> tmp;
    for (int v: a[u]) {
        if (v != p) {
            tmp = dfs(v, u);
            flag |= tmp.second;
            if (!tmp.second) {
                ret += tmp.first;
            }
        }
    }
    cnt[u] = ret;
    return make_pair(ret, flag);
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n >> x >> y;
    for (int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(x, -1);
    cout << 1LL * n * (n - 1) - 1LL * cnt[x] * cnt[y];

    return 0;
}