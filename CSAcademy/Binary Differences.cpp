#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cur = 0, prev_min = 0, prev_max = 0, max_0 = 0, max_1 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            cur++;
            max_0 = max(max_0, cur - prev_min);
            prev_max = max(cur, prev_max);
        }
        else {
            cur--;
            max_1 = max(max_1, prev_max - cur);
            prev_min = min(prev_min, cur);
        }
    }
    cout << max_0 + max_1 + 1;

    return 0;
}