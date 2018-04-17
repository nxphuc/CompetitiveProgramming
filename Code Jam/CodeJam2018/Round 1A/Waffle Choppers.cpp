#include <bits/stdc++.h>
using namespace std;

int canCut(const vector<vector<int>>& a, int r, int c, int h, int v, int r1, int c1, int cnt) {
    // int cnt_c = 1;
    vector<int> list_cut_v;
    list_cut_v.push_back(c1);
    for (int prev_c = c1, next_c = c1 + 1; next_c <= c; next_c++) {
        if (list_cut_v.size() == v && prev_c != c) {
            list_cut_v.push_back(c);
            break;
        }
        if (a[r1][next_c] - a[r1][prev_c] == cnt) {
            list_cut_v.push_back(next_c);
            prev_c = next_c;
        }
    }
    vector<int> list_cut_h;
    list_cut_h.push_back(r1);
    for (int prev_r = r1, next_r = r1 + 1; next_r <= r; next_r++) {
        if (list_cut_h.size() == h && prev_r != r) {
            list_cut_h.push_back(r);
            break;
        }
        if (a[next_r][c1] - a[prev_r][c1] == cnt) {
            list_cut_h.push_back(next_r);
            prev_r = next_r;
        }
    }
    if (list_cut_v.size() != v + 1 || list_cut_v[v] != c) {
        return 0;
    }
    if (list_cut_h.size() != h + 1 || list_cut_h[h] != r) {
        return 0;
    }
    // for (int i = 0; i <= h; i++) {
    //     cerr << list_cut_h[i] << " ";
    // }
    // cerr << "\n";
    // for (int i = 0; i <= v; i++) {
    //     cerr << list_cut_v[i] << " ";
    // }
    // cerr << "\n==============\n";
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= v; j++) {
            int num = a[list_cut_h[i]][list_cut_v[j]];
            if (i && j) {
                num += a[list_cut_h[i - 1]][list_cut_v[j - 1]];
            }
            if (i) {
                num -= a[list_cut_h[i - 1]][list_cut_v[j]];
            }
            if (j) {
                num -= a[list_cut_h[i]][list_cut_v[j - 1]];
            }
            if (num != cnt) {
                return 0;
            }
        }
    }
    return 1;
}

string doTestCase() {
    int r, c, h, v;
    vector<string> s;
    vector<vector<int>> a;

    cin >> r >> c >> h >> v;
    s.resize(r + 1);
    a.assign(r + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= r; i++) {
        cin >> s[i];
        for (int j = 1; j <= c; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (s[i][j - 1] == '@');
        }
    }
    int tot = a[r][c];
    if (tot % ((h + 1) * (v + 1))) {
        return "IMPOSSIBLE";
    }
    tot /= ((h + 1) * (v + 1));
    for (int r1 = 1; r1 <= r; r1++) {
        for (int c1 = 1; c1 <= c; c1++) {
            if (a[r1][c1] == tot) {
                if (canCut(a, r, c, h, v, r1, c1, tot)) {
                    return "POSSIBLE";
                }
            }
        }
    }
    return "IMPOSSIBLE";
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": " << doTestCase() << "\n";
    }

    return 0;
}