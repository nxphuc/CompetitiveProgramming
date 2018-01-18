#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    for (char& ch : s) {
        ch = t[ch - 'a'];
    }
    cout << s;

    return 0;
}