#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    map<long long, pair<int, int>> sums;
    int k, n;

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        vector<int> a;
        long long s = 0;
        a.resize(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            s += a[j];
        }
        for (int j = 0; j < n; j++) {
            auto pos = sums.find(s - a[j]);
            if (pos != sums.end()) {
                auto tmp = pos->second;
                if (tmp.first != i) {
                    cout << "YES\n";
                    cout << (pos->second).first + 1 << " " << (pos->second).second + 1 << "\n";
                    cout << i + 1 << " " << j + 1;
                    return 0;
                }
            }
            else {
                sums[s - a[j]] = make_pair(i, j);
            }
        }
    }
    cout << "NO";

    return 0;
}