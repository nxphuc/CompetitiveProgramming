#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 2e6 + 10;

struct Node {
    int l, r, id, query, val;

    Node(int l = 0, int r = 0, int id = 0, int query = 0, int val = 0)
        : l(l), r(r), id(id), query(query), val(val) {}
    
    bool operator<(const Node& other) const {
        if (r == other.r) {
            return query < other.query;
        }
        return r < other.r;
    }
};

int bit[MAX];
int a[MAX], tmp[MAX];
int ans[MAX];
int prv[MAX][2];
int n, q;
vector<Node> queries;

void update(int id, int val) {
    while (id < MAX) {
        bit[id] += val;
        id += id & -id;
    }
}

int get(int id) {
    int res = 0;
    while (id) {
        res += bit[id];
        id -= id & -id;
    }
    return res;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp[i] = a[i];
    }
    sort(tmp + 1, tmp + n + 1);
    for (int val, i = 1; i <= n; i++) {
        val = lower_bound(tmp + 1, tmp + n + 1, a[i]) - tmp;
        queries.push_back(Node(0, i, i, 0, val));
        update(i, 1);
    }
    cin >> q;
    for (int l, r, i = n + 1; i <= n + q; i++) {
        cin >> l >> r;
        queries.push_back(Node(l, r, i - n, 1));
    }
    sort(queries.begin(), queries.end());
    // for (Node query : queries) {
    //     cout << query.id << " " << query.l << " " << query.r << " " << query.query << " " << query.val << "\n";
    // }
    for (int i = 0; i < n + q; i++) {
        if (queries[i].query) {
            ans[queries[i].id] = get(queries[i].r) - get(queries[i].l - 1);
            // cout << "@ " << queries[i].id << " " << ans[queries[i].id] << "\n";
        }
        else {
            if (prv[queries[i].val][0]) {
                if (prv[queries[i].val][1]) {
                    update(prv[queries[i].val][1], 1);
                }
                update(prv[queries[i].val][0], -2);
                prv[queries[i].val][1] = prv[queries[i].val][0];
            }
            prv[queries[i].val][0] = queries[i].id;
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}