#include <bits/stdc++.h>
using namespace std;

int tryToSwap(string s, string t) {
    int n = s.length();
    int cnt = 0;
    if (n < 2) {
        return -1;
    }
    for (int i = 1; i >= 0; i--) {
        for (int j = n - 1 - (1 - i); j >= 0; j--) {
            if (s[j] == t[i]) {
                for (int k = j; k < n - 1 - (1 - i); k++) {
                    swap(s[k], s[k + 1]);
                    cnt++;
                }
                break;
            }
        }
    }
    if (s.substr(n - 2, 2) != t) {
        return -1;
    }
    if (s[0] == '0') {
        for (int i = 0; i < n - 2; i++) {
            if (s[i] != '0') {
                for (int j = i; j > 0; j--) {
                    swap(s[j], s[j - 1]);
                    cnt++;
                }
                break;
            }
        }
    }
    return s[0] == '0' ? -1 : cnt;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    string p[] = {"00", "25", "50", "75"};
    string s;

    cin >> s;
    int res = -1;
    for (int i = 0; i < 4; i++) {
        int tmp = tryToSwap(s, p[i]);
        // cout << p[i] << " " << tmp << "\n";
        if (tmp != -1 && (res == -1 || res > tmp)) {
            res = tmp;
        }
    }
    cout << res;

    return 0;
}