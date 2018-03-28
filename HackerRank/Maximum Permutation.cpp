#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    string a;
    int N, m;
    vector<int> SA, LCP, x, y, w, c;

    SuffixArray(string _a, int m = 256) : a(" " + _a), N(a.length()), m(m),
            SA(N), LCP(N), x(N), y(N), w(max(m, N)), c(N) {
        a[0] = 0;
        DA();
        kasaiLCP();
        #define REF(X) { rotate(X.begin(), X.begin()+1, X.end()); X.pop_back(); }
        REF(SA); REF(LCP);
        a = a.substr(1, a.size());
        for(int i = 0; i < (int) SA.size(); ++i) --SA[i];
        #undef REF
    }

    inline bool cmp (const int a, const int b, const int l) {
        return (y[a] == y[b] && y[a + l] == y[b + l]);
    }

    void Sort() {
        for (int i = 0; i < m; ++i)
            w[i] = 0;
        for (int i = 0; i < N; ++i)
            ++w[x[y[i]]];
        for (int i = 0; i < m - 1; ++i)
            w[i + 1] += w[i];
        for (int i = N - 1; i >= 0; --i)
            SA[--w[x[y[i]]]] = y[i];
    }

    void DA() {
        for (int i = 0; i < N; ++i)
            x[i] = a[i], y[i] = i;
        Sort();
        for (int i, j = 1, p = 1; p < N; j <<= 1, m = p) {
            for (p = 0, i = N - j; i < N; i++)
                y[p++] = i;
            for (int k = 0; k < N; ++k)
                if (SA[k] >= j) y[p++] = SA[k] - j;
            Sort();
            for (swap(x, y), p = 1, x[SA[0]] = 0, i = 1; i < N; ++i)
                x[SA[i]] = cmp(SA[i - 1], SA[i], j) ? p - 1 : p++;
        }
    }

    void kasaiLCP() {
        for (int i = 0; i < N; i++)
            c[SA[i]] = i;
        for (int i = 0, j, k = 0; i < N; LCP[c[i++]] = k)
            if (c[i] > 0)
                for (k ? k-- : 0, j = SA[c[i] - 1]; a[i + k] == a[j + k]; k++);
            else
                k = 0;
    }
};

void doTestCase() {
    string s, w;

    cin >> w >> s;
    int n = s.length(), m = w.length();
    vector<int> cnt_w(26, 0);
    vector<vector<int>> cnt_s(n, vector<int>(26, 0));
    for (int i = 0; i < m; i++) {
        cnt_w[w[i] - 'a']++;
        cnt_s[0][s[i] - 'a']++;
    }
    for (int i = m; i < n; i++) {
        cnt_s[i - m + 1] = cnt_s[i - m];
        cnt_s[i - m + 1][s[i - m] - 'a']--;
        cnt_s[i - m + 1][s[i] - 'a']++;
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < 26; j++) {
    //         cout << cnt_s[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    SuffixArray suffix_array(s);
    int max_count = -1;
    string res(m, 'z');
    
    for (int i = 0; i < n; i++) {
        if (cnt_s[i] == cnt_w) {
            max_count = 1;
            res = min(res, s.substr(i, m));
        }
    }

    vector<int> sa = suffix_array.SA;
    vector<int> lcp = suffix_array.LCP;
    for (int i = 0; i < n; i++) {
        if (lcp[i] >= m) {
            int cnt = 1;
            int id = i;
            while (i < n && lcp[i] >= m) {
                i++;
                cnt++;
            }
            if (cnt > max_count && cnt_s[sa[id]] == cnt_w) {
                res = s.substr(sa[id], m);
                max_count = cnt;
            }
        }
    }
    if (max_count == -1) {
        cout << "-1\n";
    }
    else {
        cout << res << "\n";
    }
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        doTestCase();
    }

    return 0;
}