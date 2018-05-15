#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, w, cur = 0, min_val = 0, max_val = 0;
    cin >> n >> w;
    for (int x, i = 1; i <= n; i++) {
        cin >> x;
        cur += x;
        min_val = min(cur, min_val);
        max_val = max(cur, max_val);
    }

    if (min_val < 0) {
        max_val -= min_val;
    }
    cout << max(0, w - max_val + 1);

    return 0;
}