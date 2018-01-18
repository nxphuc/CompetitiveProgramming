#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, m;
    vector<int> boys, girls;
    cin >> n;
    boys.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> boys[i];
    }
    cin >> m;
    girls.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> girls[i];
    }
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (abs(boys[i] - girls[j]) <= 1) {
            cnt++;
            i++;
            j++;
        }
        else if (boys[i] > girls[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    cout << cnt;

    return 0;
}