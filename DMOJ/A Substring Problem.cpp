#include <bits/stdc++.h>
using namespace std;

int isPalindrome(const string &s) {
    int r = s.length() - 1, l = 0;
    while (l < r) {
        if (s[l] != s[r]) {
            return 0;
        }
        l++;
        r--;
    }
    return 1;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    string s, t;
    int flag = 1;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n && flag; i++) {
        string t = "";
        int cnt = 0;
        for (int j = i; j < n; j++) {
            t += s[j];
            cnt++;
            if (cnt % 2 == 0 && isPalindrome(t)) {
                flag = 0;
                break;
            }
        }
    }
    cout << (flag ? "Odd" : "Even");

    return 0;
}