#include <bits/stdc++.h>
using namespace std;

int doTestCase() {
    int n, l, half;
    vector<int> next;

    cin >> n >> l;
    next.resize(n + 1, -1);

    int temp = n;
    for (int i = n; i >= 0; i--) {
        if ((100 * i) % n >= (n + 1) / 2) {
            temp = i;
        }
        next[i] = temp;
    }

    vector<pair<int, int>> list_voted;
    int total_voted = 0;
    int res = 0;
    for (int voted, need_to_next, i = 0; i < l; i++) {
        cin >> voted;
        need_to_next = next[voted] - voted;
        list_voted.push_back(make_pair(need_to_next, voted));
        total_voted += voted;
    }
    for (int i = total_voted; i < n; i++) {
        list_voted.push_back(make_pair(next[0], 0));
    }
    sort(list_voted.begin(), list_voted.end());
    for (auto vote: list_voted) {
        if (vote.first <= n - total_voted) {
            total_voted += vote.first;
            res += round((vote.first + vote.second) * 100.0 / n);
        }
        else {
            res += round(vote.second * 100.0 / n);
        }
    }
    return res + round((n - total_voted) * 100.0 / n);
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