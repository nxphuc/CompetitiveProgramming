#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.length();
    set<int> pos[2];
    for (int i = 0; i < n; i++) {
        pos[s[i] - '0'].insert(i + 1);
    }

    int res = 0;
    int last0, last1;
    set<int>::iterator it;
    vector<vector<int>> f;
    while (pos[0].size() > 0) {
        f.push_back(vector<int>());
        last0 = *pos[0].begin();
        f[res].push_back(last0);
        pos[0].erase(last0);
        while (true) {
            it = pos[1].lower_bound(last0);
            if (it == pos[1].end()) {
                break;
            }

            last1 = *it;
            it = pos[0].lower_bound(last1);
            if (it == pos[0].end()) {
                break;
            }
            last0 = *it;
            f[res].push_back(last1);
            f[res].push_back(last0);
            pos[0].erase(last0);
            pos[1].erase(last1);
        }
        res++;
    }
    if (pos[0].empty() && pos[1].empty()) {
        cout << res << "\n";
        for (int i = 0; i < res; i++) {
            cout << f[i].size();
            for (int j = 0; j < f[i].size(); j++) {
                cout << " " << f[i][j];
            }
            cout << "\n";
        }
    }
    else {
        cout << -1;
    }

    return 0;
}