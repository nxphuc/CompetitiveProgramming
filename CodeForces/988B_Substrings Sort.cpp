#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    vector<string> a;
    string s;

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].find(a[j]) != string::npos) {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i].find(a[i - 1]) == string::npos) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (auto s: a) {
        cout << s << "\n";
    }

    return 0;
}