#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e10;

int doTestCase() {
    int n;
    ll min_weight[2][150];
    ll ant, carry;
    int cur = 0, prv;

    for (int i = 1; i < 150; i++) {
        min_weight[0][i] = min_weight[1][i] = INF;
    }
    min_weight[0][0] = min_weight[1][0] = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ant;
        prv = cur;
        cur = 1 - cur;
        for (int j = 1; j < 150; j++) {
            if (ant * 6 >= min_weight[prv][j - 1]) {
                min_weight[cur][j] = min(min_weight[prv][j], min_weight[prv][j - 1] + ant);
            }
            else {
                min_weight[cur][j] = min_weight[prv][j];
            }
        }
    }
    for (int i = 149; i >= 0; i--) {
        if (min_weight[cur][i] < INF) {
            return i;
        }
    }
    exit(1);
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": " << doTestCase() << "\n";
    }

    return 0;
}