#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n;
    cin >> s;
    if (n == 1) {
        cout << s;
    }
    else {
        int cnt[2] = {0, 0};
        for (char ch : s) {
            cnt[ch - '0']++;
        }
        cout << '1';
        while (cnt[0]--) {
            cout << '0';
        }
    }

    return 0;
}