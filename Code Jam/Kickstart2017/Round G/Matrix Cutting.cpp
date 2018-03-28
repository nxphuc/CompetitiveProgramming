#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
const int INF = 1e9;

int t, n, m;
int a[MAX][MAX];
int f_min[MAX][MAX][MAX][MAX];
int f[MAX][MAX][MAX][MAX];

void doTestCase() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    memset(f, 0, sizeof(f));
    memset(f_min, 0x7f, sizeof(f_min));

    for (int rx = 0; rx < n; rx++) {
        for (int lx = rx; lx >= 0; lx--) {
            for (int ry = 0; ry < m; ry++) {
                for (int ly = ry; ly >= 0; ly--) {
                    if (lx == rx && ly == ry) {
                        f_min[lx][rx][ly][ry] = a[lx][ly];
                        f[lx][rx][ly][ry] = 0;
                    }
                    else {
                        for (int x = lx; x < rx; x++) {
                            f_min[lx][rx][ly][ry] = min(f_min[lx][x][ly][ry], f_min[x+1][rx][ly][ry]);
                            f[lx][rx][ly][ry] = max(f[lx][rx][ly][ry], 
                                f[lx][x][ly][ry] + f[x + 1][rx][ly][ry] + f_min[lx][rx][ly][ry]);
                        }
                        for (int y = ly; y < ry; y++) {
                            f_min[lx][rx][ly][ry] = min(f_min[lx][rx][ly][y], f_min[lx][rx][y+1][ry]);
                            f[lx][rx][ly][ry] = max(f[lx][rx][ly][ry], 
                                f[lx][rx][ly][y] + f[lx][rx][y+1][ry] + f_min[lx][rx][ly][ry]);
                        }
                    }
                }
            }
        }
    }

    cout << f[0][n-1][0][m-1] << "\n";
}

int main() {
    // freopen("test.in", "rt", stdin);
    freopen("C-large-practice.in", "rt", stdin);
    freopen("C-large-practice.ou", "wt", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        doTestCase();
    }

    return 0;
}