#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    vector<long long> a;

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> f;
    f.push_back(a[0]);
    for (int i = 0; i < n && f.size() != 3; i++) {
        for (long long j = 0; j < 31; j++) {
            long long x = a[i] + (1LL << j);
            int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
            if (pos != n && a[pos] == x) {
                f.clear();
                f.push_back(a[i]);
                f.push_back(x);

                long long y = x + (1LL << j);
                pos = lower_bound(a.begin(), a.end(), y) - a.begin();
                if (pos != n && a[pos] == y) {
                    f.push_back(y);
                    break;
                }
            }
        }
    }
    cout << f.size() << "\n";
    for (auto x: f) {
        cout << x << " ";
    }

    return 0;
}