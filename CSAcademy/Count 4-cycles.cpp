#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, cnt = 0;
    set<pair<int,int>> edges;

    cin >> n;
    for (int x, y, i = 1; i < n; i++) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        edges.insert({x, y});
    }
    for (int x, y, i = 1; i < n; i++) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        cnt += edges.find({x, y}) != edges.end();
    }
    cout << cnt;

    return 0;
}