#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int n;
int a[MAX];
int f[MAX][MAX][2];

int dp(int l, int r, int mask) {
    if (f[l][r][mask] != -1) {
        return f[l][r][mask];
    }
    if ((a[l] * a[r]) % 2 != mask) {
        return f[l][r][mask] = 0;
    }
    if (l == r) {
        return f[l][r][mask] = mask == 1;
    }
    if ((r - l + 1) % 2 == 1 && mask == 1) {
        return f[l][r][mask] = 1;
    }
    for (int cnt_1, cnt_2, i = l; i < r; i++) {
        if (mask) {
            if ((dp(l, i, 1) && dp(i + 1, r, 0)) || (dp(l, i, 0) && dp(i + 1, r, 1))) {
                return f[l][r][1] = 1;
            }
        }
        else {
            if ((dp(l, i, 1) && dp(i + 1, r, 1)) || (dp(l, i, 0) && dp(i + 1, r, 0))) {
                return f[l][r][0] = 1;
            }
        }
    }
    return f[l][r][mask] = 0;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    memset(f, -1, sizeof(f));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << (dp(0, n-1, 1) ? "yes" : "no");

    return 0;
}