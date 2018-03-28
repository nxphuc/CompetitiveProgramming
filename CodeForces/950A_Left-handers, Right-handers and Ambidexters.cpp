#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int l, r, a;
    cin >> l >> r >> a;
    int res = min(l, r);
    l = max(l - res, r - res);
    res *= 2;
    res += min(l, a) * 2;
    a -= min(l, a);
    if (a) {
        res += a/2 * 2;
    }
    cout << res;

    return 0;
}