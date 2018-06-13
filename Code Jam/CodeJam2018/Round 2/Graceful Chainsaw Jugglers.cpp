#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;

int f[MAX][MAX][MAX][MAX];

int dp(int r, int b, int lr, int lb) {
    if (r == 0 && b == 0) {
        return 0;
    }
    if (f[r][b][lr][lb] != -1) {
        return f[r][b][lr][lb];
    }
    
    for (int nr = lr; nr <= r; nr++) {
        for (int nb = (nr == lr ? lb + 1 : 0); nb <= b; nb++) {
            f[r][b][lr][lb] = max(f[r][b][lr][lb], dp(r - nr, b - nb, nr, nb) + 1);
        }
    }
    return f[r][b][lr][lb];
}

int greedy(int r, int b) {
    if (r > b) {
        swap(r, b);
    }
    int res = 0;
    for (int i = 0; i <= r; i++) {
        int sum_r = i * (i + 1) / 2;
        for (int j = 0; j <= b; j++) {
            int sum_b = j * (j + 1) / 2;
            if (sum_r * j <= r && sum_b * i <= b) {
                res = max(res, (i + 1) * (j + 1));
            }
            else {
                int cnt = b / sum_b;
                int tmp_b = b - cnt * sum_b;
            }
        }
    }
    return res;
}

void doTestCase() {
    int r, b;
    cin >> r >> b;
    cout << dp(r, b, 0, 0) << "\n";
}

int main() {
    freopen("test.in", "rt", stdin);
    freopen("test.ou", "wt", stdout);
    ios::sync_with_stdio(false);

    memset(f, -1, sizeof(f));

    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            int f_dp = dp(i, j, 0, 0);
            int f_gr = greedy(i, j);
            if (f_dp != f_gr) {
                cout << i << " " << j << " " << f_dp << " " << f_gr << "\n";
            }
        }
    }

    // int t;
    // cin >> t;
    // for (int cs = 1; cs <= t; cs++) {
    //     cout << "Case #" << cs << ": ";
    //     doTestCase();
    // }
    return 0;
}