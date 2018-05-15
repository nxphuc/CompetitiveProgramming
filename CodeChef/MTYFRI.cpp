#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a, b;
        long long sum_a = 0, sum_b = 0;

        for (int x, i = 0; i < n; i++) {
            cin >> x;
            if (i & 1) {
                b.push_back(x);
                sum_b += x;
            }
            else {
                a.push_back(x);
                sum_a += x;
            }
        }
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());
        for (int i = 0; i < k; i++) {
            if (i >= a.size() || i >= b.size() || a[i] <= b[i]) {
                break;
            }
            sum_a += b[i] - a[i];
            sum_b += a[i] - b[i];
        }
        // cout << sum_a << " " << sum_b << "\n";
        cout << (sum_a < sum_b ? "YES\n" : "NO\n");
    }

    return 0;
}