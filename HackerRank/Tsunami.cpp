#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;
typedef long long ll;

ll it[4 * MAX];
pair<int, ll> islands[MAX];
int locations[MAX];
map<int, int> locations_map;

void update(int id, int l, int r, int pos, ll val) {
    if (l == pos && pos == r) {
        it[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(id * 2, l, mid, pos, val);
    }
    else {
        update(id * 2 + 1, mid + 1, r, pos, val);
    }
    it[id] = max(it[id * 2], it[id * 2 + 1]);
}

int query(int id, int l, int r, int pos, ll val) {
    // cout << "# " << id << " " << it[id] << " " << l << " " << r << " " << pos << " " << val << "\n";
    if (it[id] <= val || r < pos) {
        return -1;
    }
    if (l == r) {
        return it[id] > val ? l : -1;
    }
    int mid = (l + r) / 2;
    int res = query(id * 2, l, mid, pos, val);
    if (res == -1) {
        res = query(id * 2 + 1, mid + 1, r, pos, val);
    }
    return res;
}

int get(int id, int l, int r, int pos) {
    if (l == r) {
        return it[id];
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        return get(id * 2, l, mid, pos);
    }
    return get(id * 2 + 1, mid + 1, r, pos);
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> islands[i].first >> islands[i].second;
        locations_map[islands[i].first] = i;
        locations[i] = islands[i].first;
    }
    sort(locations + 1, locations + n + 1);
    for (int i = 1; i <= n; i++) {
        islands[i].first = lower_bound(locations + 1, locations + n + 1, islands[i].first) - locations;
        update(1, 1, n, islands[i].first, islands[i].second);
    }

    int q, x;
    char ch;

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> ch >> x;
        if (ch == 'd') {
            x = locations_map[x];
            update(1, 1, n, islands[x].first, -1);
            islands[x].second = -1;
        }
        else {
            if (islands[x].second == -1) {
                cout << "DROWNED\n";
            }
            else {
                x = query(1, 1, n, islands[x].first, islands[x].second);
                if (x == -1) {
                    cout << "IMPOSSIBLE\n";
                }
                else {
                    cout << locations[x] << "\n";
                }
            }
        }
    }

    return 0;
}