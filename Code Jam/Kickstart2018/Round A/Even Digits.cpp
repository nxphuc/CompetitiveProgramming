#include <bits/stdc++.h>
using namespace std;

long long solve(long long n) {
    string s = to_string(n);
    int id = -1;
    int m = s.length();
    for (int i = 0; i < m; i++) {
        if (s[i] & 1) {
            id = i;
            break;
        }
    }
    if (id == -1) {
        return 0;
    }
    long long pw = 1;
    for (int i = id + 1; i < m; i++) {
        pw *= 10;
    }
    long long up = (n / pw + 1) * pw;
    long long down = (n / pw - 1) * pw;
    pw = 0;
    // cout << "# " << down << "\n";
    for (int i = id + 1; i < m; i++) {
        pw = pw * 10 + 8;
    }
    down += pw;
    if (s[id] == '9') {
        return n - down;
    }
    // cout << up << " " << down << "\n";
    return min(up - n, n - down);
}

int main() {
    // freopen("test.in", "rt", stdin);
    freopen("A-large.in", "rt", stdin);
    freopen("A-large.ou", "wt", stdout);
    ios::sync_with_stdio(false);

    int t;
    long long n;

    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cin >> n;
        cout << "Case #" << cs << ": " << solve(n) << "\n";
    }

    return 0;
}