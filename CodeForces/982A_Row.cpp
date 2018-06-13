#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    string s;

    cin >> n;
    cin >> s;
    s = "0" + s + "0";
    
    int cnt = 0;
    for (char ch : s) {
        if (ch == '0') {
            cnt += 1;
        }
        else {
            if (!cnt) {
                cout << "No";
                return 0;
            }
            cnt = 0;
        }
        if (cnt > 2) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}