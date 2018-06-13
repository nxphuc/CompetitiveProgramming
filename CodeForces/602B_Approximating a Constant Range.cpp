#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int last_diff = a[1] - a[0];
    int last_diff_pos = last_diff ? 0 : -1;
    int cur_length = 2;
    int res = 2;
    
    for (int i = 2; i < n; i++) {
        int diff = a[i] - a[i - 1];
        if (diff) {
            if (diff == last_diff) {
                cur_length = i - last_diff_pos; // make new constant range
            }
            else {
                cur_length++; // extend current constant range to index i
            }
            last_diff = diff;
            last_diff_pos = i - 1;
        }
        else {
            cur_length++; // extend current constant range to index i
        }
        res = max(res, cur_length);
    }
    cout << res << "\n";

    return 0;
}