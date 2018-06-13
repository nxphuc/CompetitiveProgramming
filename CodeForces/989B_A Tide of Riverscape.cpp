#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, p, flag = 0;
    string s;

    cin >> n >> p;
    cin >> s;
    for (int i = 0; i < p && !flag; i++) {
        for (int k = i, j = i + p; j < n; k = j, j += p) {
            if (s[j] == '.' && s[k] == '.') {
                s[j] = '0';
                s[k] = '1';
                flag = 1;
                break;
            }
            else if (s[j] == '.') {
                s[j] = '1' + '0' - s[k];
                flag = 1;
                break;
            }
            else if (s[k] == '.') {
                s[k] = '1' + '0' - s[j];
                flag = 1;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            s[i] = '0';
        }
    }
    flag = 0;
    for (int i = 0; i + p < n; i++) {
        if (s[i] != s[i + p]) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        cout << s;
    }
    else {
        cout << "No";
    }

    return 0;
}