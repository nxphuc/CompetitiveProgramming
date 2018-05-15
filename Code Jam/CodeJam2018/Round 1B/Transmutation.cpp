#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e11 + 10;

vector<ll> g, tmp;
vector<int> vis;
vector<pair<int, int>> r;

int canMake(ll need, int id) {
    if (vis[id]) {
        return 0;
    }
    
    int res = 0;
    vis[id] = 1;
    if (tmp[id] >= need) {
        tmp[id] -= need;
        res = 1;
    }
    else {
        need -= tmp[id];
        tmp[id] = 0;
        res = canMake(need, r[id].first) && canMake(need, r[id].second);
    }

    vis[id] = 0;
    return res;
}

ll doTestCase() {
    int n;
    cin >> n;

    vis.assign(n, 0);
    g.resize(n);
    r.resize(n);

    for (int x, y, i = 0; i < n; i++) {
        cin >> x >> y;
        r[i] = make_pair(x - 1, y - 1);
    }
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    ll mi, lo = 0, hi = INF;
    ll res = 0;
    while (lo <= hi) {
        mi = (lo + hi) / 2;
        
        tmp = g;
        fill(vis.begin(), vis.end(), 0);
        if (canMake(mi, 0)) {
            res = mi;
            lo = mi + 1;
        }
        else {
            hi = mi - 1;
        }
    }
    return res;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": " << doTestCase() << "\n";
    }

    return 0;
}