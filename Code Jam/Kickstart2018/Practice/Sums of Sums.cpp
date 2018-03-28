#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e5 + 10;

ll s[MAX], a[MAX];
int n;
ll mn;

ll countLower(ll val) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += upper_bound(a + i, a + n + 1, val + a[i - 1]) - (a + i);
    }
    return cnt;
}

ll findValue(ll pos) {
    ll mid, low = mn, high = a[n], res = -1;
    while (low <= high) {
        mid = (low + high) >> 1;
        ll cnt = countLower(mid);
        if (cnt < pos) {
            low = mid + 1;
        }
        else {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}

ll getSum(ll val) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(a + 1, a + n + 1, val + a[i - 1]) - a - 1;
        sum += s[pos] - a[i - 1] * (pos - i);
    }
    return 0;
}

ll query(ll l, ll r) {
    ll low = findValue(l);
    ll high = findValue(r);
    
    if (low == high) {
        return (r - l + 1) * low;
    }
    ll res = low * (countLower(low) - l + 1) + high * (r - countLower(high - 1));
    for (int i = 1; i <= n; i++) {
        int right = lower_bound(a + 1, a + n + 1, high + a[i - 1]) - a - 1;
        int left = upper_bound(a, a + n + 1, low + a[i - 1]) - a;
        res += s[right] - s[left - 1] - a[i - 1] * (right - left + 1);
    }
    return res;
}

void doTestCase() {
    int q;
    ll l, r;

    cin >> n >> q;
    mn = 101;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        a[i] += a[i-1];
        s[i] = s[i-1] + a[i];
    }

    while (q--) {
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }
}

int main() {
    freopen("D-large-practice.in", "rt", stdin);
    freopen("D-large-practice.ou", "wt", stdout);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ":\n";
        doTestCase();
    }

    return 0;
}