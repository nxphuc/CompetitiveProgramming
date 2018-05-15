#include <bits/stdc++.h>
using namespace std;

void doTestCase() {
    vector<int> mark, cnt;
    int n, d, x;

    cin >> n;
    mark.assign(n, 0);
    cnt.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> d;
        vector<int> liked;
        vector<int> picked;

        for (int j = 0; j < d; j++) {
            cin >> x;
            liked.push_back(x);
            cnt[x]++;
        }
        int res = -1;
        for (int j : liked) {
            if (!mark[j]) {
                if (res == -1 || cnt[res] > cnt[j]) {
                    res = j;
                    picked.clear();
                }
                if (cnt[res] == cnt[j]) {
                    picked.push_back(j);
                }
            }
        }
        if (picked.size() == 0) {
            cout << "-1\n";
        }
        else {
            res = picked[rand() % picked.size()];
            cout << res << "\n";
            mark[res] = 1;
        }
        fflush(stdout);
    }
}


int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        doTestCase();
    }

    return 0;
}