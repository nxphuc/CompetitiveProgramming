#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5 + 10;
const int INF = 1e9;

int n;
ll a[MAX];

int test(ll st, ll nd) {
    int res = (st != a[0]) + (nd != a[1]);
    ll diff = nd - st;
    ll next_val = nd + diff;

    for (int i = 2; i < n; i++) {
        int cur_dif = abs(next_val - a[i]);
        if (cur_dif == 1) {
            res++;
        }
        else if (cur_dif > 1) {
            return INF;
        }
        next_val += diff;
    }

    return res;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n < 3) {
        cout << 0;
    }
    else {
        int res = INF;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                res = min(res, test(a[0] + i, a[1] + j));
            }
        }
        cout << (res == INF ? -1 : res);
    }

    return 0;
}