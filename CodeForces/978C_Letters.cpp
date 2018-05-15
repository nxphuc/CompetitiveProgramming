#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5 + 10;

ll a[MAX];
int n, m;

pair<ll, ll> calcRoom(ll id) {
    ll dorm_id = lower_bound(a, a + n + 1, id) - a;
    ll room_id = id - a[dorm_id - 1];
    return make_pair(dorm_id, room_id);
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    ll id;
    for (int i = 0; i < m; i++) {
        cin >> id;
        pair<ll, ll> res = calcRoom(id);
        cout << res.first << " " << res.second << "\n";
    }

    return 0;
}