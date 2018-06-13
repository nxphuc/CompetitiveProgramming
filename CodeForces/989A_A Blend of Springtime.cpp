#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s;
    for (int i = 0; i + 2 < s.length(); i++) {
        t = s.substr(i, 3);
        sort(t.begin(), t.end());
        if (t == "ABC") {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}