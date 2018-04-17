#include <bits/stdc++.h>
using namespace std;

long long solve(string s) {
    int n = s.length();
    vector<vector<int>> f(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        f[i][i] = 1;
        if (i < n-1 && s[i] == s[i + 1]) {
            f[i][i + 1] = 1;
        }
        for (int j = i + 2; j < n; j++) {
            f[i][j] = f[i+1][j - 1] && s[i] == s[j];
        }
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (f[i][j]) {
                res += (j - i + 1) * (j - i + 1);
            }
        }
    }
    return res;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    string s;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        cout << solve(s) << "\n";
    }

    return 0;
}