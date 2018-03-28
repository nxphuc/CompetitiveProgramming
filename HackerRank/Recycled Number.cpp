#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, m;
    vector<string> a;
    set<string> set_a;
    set<pair<string,string>> list_result;
    string s, t;

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        set_a.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        s = t = a[i];
        m = s.length();
        for (int j = 1; j < m; j++) {
            t = t.substr(1) + t[0];
            if (t < s && t[0] != '0' && set_a.find(t) != set_a.end()) {
                list_result.insert(make_pair(s, t));
            }
        }
    }
    cout << list_result.size();

    return 0;
}