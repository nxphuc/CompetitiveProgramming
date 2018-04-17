#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 2e18;
const int MAX = 110;

double doTestCase() {
    int w[MAX], h[MAX];
    int n, p;

    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i];
        if (w[i] < h[i]) {
            swap(h[i], w[i]);
        }
    }
    int flag = 1;
    for (int i = 1; i < n; i++) {
        flag &= w[i] == w[i - 1];
        flag &= h[i] == h[i - 1];
    }
    if (flag) {
        double s = (double)n * 2.0 * (w[0] + h[0]);
        double res = 0;
        double lo = 2*h[0];
        double hi = 2*sqrt(h[0] * h[0] + w[0] * w[0]);
        for (int i = 0; i <= n; i++) {
            if (hi * i + s > p) {
                break;
            }
            double remain = p - s - hi * i;
            for (int j = 0; j <= n; j++) {
                if (i + j > n) {
                    break;
                }
                // cout << i << " " << j << " " << remain << " " << hi * (i + j) << "\n";
                if (remain >= lo * j && remain <= hi * j) {
                    return p;
                }
                if (remain >= hi * j) {
                    res = max(res, hi * (i + j));
                }
            }
        }
        return s + res;
    }
    return 0;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": " << fixed << setprecision(10) << doTestCase() << "\n";
    }

    return 0;
}