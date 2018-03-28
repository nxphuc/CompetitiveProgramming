#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e6 + 10;
const ll MOD = 1e9 + 9;
const ll BASE = 239;

ll power[MAX];
pair<ll, int> hash_index[MAX];

ll getHash(int l, int r) {
    return hash_index[r].first - hash_index[l - 1].first * power[r - l + 1];
}

void doTestCase() {
    string s, t;
    cin >> s >> t;

    ll hash_s = 0;
    int n = s.length();
    int m = t.length();

    for (int i = 1; i <= n; i++) {
        hash_s = hash_s * BASE + s[i - 1] - 'a';
    }
    // cout << "# " << hash_s << "\n";

    int res = 0;
    int current_size = 0;
    hash_index[0] = make_pair(0LL, 0);
    for (int i = 1; i <= m; i++) {
        current_size++;
        hash_index[current_size] = make_pair(hash_index[current_size - 1].first * BASE + t[i - 1] - 'a', i);
        if (current_size >= n && getHash(current_size - n + 1, current_size) == hash_s) {
            res++;
            current_size -= n;
        }
    }
    // for (int i = 0; i <= m; i++) {
    //     cout << hash_index[i].first << " " << hash_index[i].second << "\n";
    // }
    cout << res << "\n";
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int num_case;
    

    power[0] = 1;
    for (int i = 1; i < MAX; i++) {
        power[i] = power[i - 1] * BASE;
    }

    cin >> num_case;
    while (num_case--) {
        doTestCase();
    }

    return 0;
}