#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int INF = 1e9 + 10;

int a[MAX];
pair<int, int> b[MAX];
int nxt[MAX], prv[MAX], del[MAX];
int n;
map<int, int> segments;

void remove(int id) {
    int l = id, r = id;
    if (del[id - 1]) {
        l = prv[id - 1];
        if (segments[id - l] == 1) {
            segments.erase(id - l);
        }
        else {
            segments[id - l]--;
        }
    }
    if (del[id + 1]) {
        r = nxt[id + 1];
        if (segments[r - id] == 1) {
            segments.erase(r - id);
        }
        else {
            segments[r - id]--;
        }
    }
    del[id] = 1;
    nxt[l] = r;
    prv[r] = l;
    segments[r - l + 1]++;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = make_pair(a[i] + 1, i);
    }
    
    sort(b + 1, b + n + 1);
    int res = INF, cur_max = 1;
    for (int i = 1; i <= n; i++) {
        remove(b[i].second);
        // cout << segments.size() << "\n";
        if (segments.size() == 1) {
            int cnt = segments.begin()->second;
            if (cnt > cur_max || (cnt == cur_max && b[i].first < res)) {
                res = b[i].first;
                cur_max = cnt;
            }
        }
    }
    cout << res;

    return 0;
}