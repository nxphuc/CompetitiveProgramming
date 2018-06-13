#include <bits/stdc++.h>
using namespace std;

void doTestCase() {
    int c;
    cin >> c;

    vector<int> a(c), lft(c, -1), rht(c, -1);
    for (int i = 0; i < c; i++) {
        cin >> a[i];
    }
    if (a[0] == 0 || a[c - 1] == 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int cur_l = 0;
    int mx = 1;
    for (int i = 0; i < c; i++) {
        if (a[i]) {
            lft[i] = cur_l;
            rht[i] = cur_l + a[i] - 1;
            cur_l += a[i];
            mx = max(mx, max(i - lft[i], rht[i] - i) + 1);
        }
    }
    cout << mx << "\n";
    vector<string> matrix(mx, string(c, '.'));
    // for (string line: matrix) {
    //     cout << line << "\n";
    // }
    for (int i = 0; i < c; i++) {
        if (a[i]) {
            // cout << lft[i] << " " << rht[i] << "\n";
            for (int x = lft[i], y = 0; x < i; x++, y++) {
                matrix[y][x] = '\\';
            }
            for (int x = rht[i], y = 0; x > i; x--, y++) {
                matrix[y][x] = '/';
                // cout << i << " " << x << " " << y << "\n";
            }
        }
    }
    for (string line: matrix) {
        cout << line << "\n";
    }
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