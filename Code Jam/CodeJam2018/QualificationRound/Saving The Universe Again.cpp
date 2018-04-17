#include <bits/stdc++.h>
using namespace std;

int calcDamage(string s) {
    int res = 0;
    int curPow = 1;
    for (char ch : s) {
        if (ch == 'C') {
            curPow <<= 1;
        }
        else {
            res += curPow;
        }
    }
    return res;
}

void doTestCase() {
    int d;
    string s;
    cin >> d >> s;
    
    int res = 0;
    int n = s.length();
    while (calcDamage(s) > d) {
        int flag = -1;
        for (int i = n - 1; i > 0; i--) {
            if (s[i] == 'S' && s[i - 1] == 'C') {
                flag = i;
                break;
            }
        }
        if (flag == -1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        res++;
        s[flag] = 'C';
        s[flag - 1] = 'S';
    }
    cout << res << "\n";
}

int main() {
    // freopen("test.in", "rt", stdin);
    // freopen("test.ou", "wt", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        doTestCase();
    }

    return 0;
}