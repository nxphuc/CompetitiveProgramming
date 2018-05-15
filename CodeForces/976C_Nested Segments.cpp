#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int cmp(piii a, piii b) {
    if (a.first.first != b.first.first) {
        return a.first.first < b.first.first;
    }
    return a.first.second > b.first.second;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    vector<piii> segments;

    cin >> n;
    for (int l, r, i = 0; i < n; i++) {
        cin >> l >> r;
        segments.push_back(make_pair(make_pair(l, r), i));
    }
    sort(segments.begin(), segments.end(), cmp);
    // for (int i = 0; i < n; i++) {
    //     cout << segments[i].first.first << " " << segments[i].first.second << " " << segments[i].second << "\n";
    // }
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (segments[i].first.second <= segments[j].first.second) {
            cout << segments[i].second + 1 << " " << segments[j].second + 1;
            return 0;
        }
        else {
            j = i;
        }
    }
    cout << "-1 -1";

    return 0;
}