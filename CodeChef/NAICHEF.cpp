#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t, n, x, y;
    vector<int> cnt;

    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        cnt.assign(n + 1, 0);
        for (int tmp, i = 0; i < n; i++) {
            cin >> tmp;
            cnt[tmp]++;
        }
        cout << fixed << setprecision(10) << 1.0 * cnt[x] * cnt[y] / n / n << "\n";
    }

    return 0;
}