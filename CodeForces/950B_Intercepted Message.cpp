#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, m;
    vector<int> a, b;
    ll sum_a = 0, sum_b = 0;
    int res = 0;

    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    for (int i = 0, j = 0; i < n; i++) {
        sum_a += a[i];
        while (j < m && sum_b < sum_a) {
            sum_b += b[j];
            j++;
        }
        if (sum_a == sum_b) {
            res++;
            sum_a = sum_b = 0;
        }
    }
    cout << res;

    return 0;
}