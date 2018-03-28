#include <bits/stdc++.h>
using namespace std;

// 01010101010
// 01110111010

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, cnt = 0;
    string s;

    cin >> n;
    cin >> s;
    for (int i = 2; i < n; i++) {
        if (s[i - 2] == '0' && s[i-1] == '1' && s[i] == '0') {
            s[i] = '1';
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}