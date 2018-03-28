#include <bits/stdc++.h>
using namespace std;

int isLatinSquare(const vector<string> & a, int n) {
    map<char, int> base;
    for (int i = 0; i < 10; i++) {
        base[i + '0'] = i;
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        base[i] = i - 'A' + 10;
    }

    vector<vector<int>> col(n, vector<int>(n, 0)), row(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            row[i][base[a[i][j]]]++;
            col[j][base[a[i][j]]]++;
            if (row[i][base[a[i][j]]] > 1 || col[j][base[a[i][j]]] > 1) {
                return 0;
            }
        }
    }
    return 1;
}

int isIncreasing(string s) {
    string t = s;
    sort(t.begin(), t.end());
    return s == t;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    vector<string> a;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s = a[0];
    string t = "";
    for (int i = 0; i < n; i++) {
        t += a[i][0];
    }
    if (isLatinSquare(a, n)) {
        if (isIncreasing(s) && isIncreasing(t)) {
            cout << "Reduced";
        }
        else {
            cout << "Latin";
        }
    }
    else {
        cout << "No";
    }

    return 0;
}