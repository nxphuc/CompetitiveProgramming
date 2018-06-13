#include <bits/stdc++.h>
using namespace std;

void doTestCase() {
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int x, i = 0; i < n; i++) {
        v.push_back(vector<int>());
        for (int j = 0; j < n; j++) {
            cin >> x;
            v[i].push_back(x);
        }
    }
    int m = n * n;
    int bits = 1 << m;
    int res = n * n;
    for (int i = 0; i < bits; i++) {
        vector<int> lst(m, 0);
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                lst[j] = 1;
                cnt++;
            }
        }
        // for (int j = 0; j < m; j++) {
        //     cout << lst[j] << " ";
        // }
        // cout << "\n";
        int flag = 1;
        for (int j = 0; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                if (!lst[j] && !lst[k] && (j / n == k / n || j % n == k % n) && v[j / n][j % n] == v[k / n][k % n]) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            res = min(res, cnt);
        }
    }
    cout << res << "\n";
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        doTestCase();
    }
    return 0;
}