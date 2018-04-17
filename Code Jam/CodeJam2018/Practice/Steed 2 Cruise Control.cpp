#include <bits/stdc++.h>
using namespace std;

void doTestcase() {
    int d, n, k, s;
    double max_time = 0;

    cin >> d >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> s;
        max_time = max(max_time, 1.0*(d - k) / s);
    }
    cout << fixed << setprecision(10) << d / max_time << "\n";
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        doTestcase();
    }

    return 0;
}