#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    double x, dist = 0;
    double a[1010];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        dist += pow(a[i] - x, 2);
    }
    cout << fixed << setprecision(10) << sqrt(dist);

    return 0;
}