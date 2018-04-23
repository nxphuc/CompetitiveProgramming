#include <bits/stdc++.h>
using namespace std;

const int MAX = 2500 * 81;

int dp[MAX];
int mark_w[MAX];
int mark_r[MAX];

int main() {
    // freopen("test.in", "rt", stdin);
    // freopen("test.ou", "wt", stdout);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a;
    int min_width = 0, max_width = 0;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a.push_back(s.length());
        min_width = max(min_width, a.back());
        max_width += a[i] + 1;
    }
    
    pair<int, int> res = {-1, -1};
    int cur, prv, cur_col, prv_col, tmp;
    
    memset(mark_w, -1, sizeof(mark_w));
    for (int w = min_width; w < max_width; w++) {
        cur = 0, prv = -1, cur_col = -1;

        for (const int& l: a) {
            if (cur_col > -1 && cur_col + l < w) {
                tmp = 1;
                for (int i = -1; i < 2; i++) {
                    prv_col = cur_col + i;
                    if (prv_col < 0 || prv_col >= w) {
                        continue;
                    }
                    if (mark_w[prv_col] != w) {
                        mark_w[prv_col] = w;
                        dp[prv_col] = 0;
                        mark_r[prv_col] = prv;
                    }
                    if (mark_r[prv_col] != prv) {
                        continue;
                    }
                    tmp = max(tmp, dp[prv_col] + 1);
                }

                dp[cur_col] = tmp;
                mark_w[cur_col] = w;
                mark_r[cur_col] = cur;
                if (tmp > res.second) {
                    res = {w, tmp};
                }
            }
            cur_col += l + 1;
            if (cur_col >= w) {
                cur_col = cur_col == w ? -1 : l;
                cur++;
                prv++;
            }
        }
    }
    cout << res.first << " " << res.second;

    return 0;
}