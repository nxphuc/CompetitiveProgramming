#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, d;
    vector<int> a;
    cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 0;
    long long res = 0;
    while (l < n) {
        while (r < n && a[r] - a[l] <= d) {
            r++;
        }
        res += 1LL * (r - l - 1) * (r - l - 2) / 2;
        l++;
    }
    cout << res;

    return 0;
}