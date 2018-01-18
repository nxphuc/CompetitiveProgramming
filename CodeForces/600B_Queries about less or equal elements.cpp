#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, m;
    vector<int> f, a;
    vector<pair<int,int>> b;

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    b.resize(m);
    for (int j = 0; j < m; j++) {
        cin >> b[j].first;
        b[j].second = j;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0;
    f.resize(m);
    for (int j = 0; j < m; j++) {
        while (i < n && a[i] <= b[j].first) {
            i++;
        }
        f[b[j].second] = i;
    }
    for (int i = 0; i < m; i++) {
        cout << f[i] << " ";
    }

    return 0;
}