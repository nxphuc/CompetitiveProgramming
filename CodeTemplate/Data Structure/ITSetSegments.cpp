#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 2e5;
int n, m, it[MAX * 5];

struct NodeData {
    ll s, e, v, d;
};
NodeData data[MAX];

ll cal(const int& id, const int& pos) {
    return data[id].v +
        data[id].d * (pos - data[id].s);
}

void down(const int& lef, const int& rig,
        const int& k, const int& id) {
    if (it[k] == -1) {
        it[k] = id;
        return;
    }
    if (cal(id, lef) <= cal(it[k], lef) &&
            cal(id, rig) <= cal(it[k], rig))
        return;
    if (cal(id, lef) >= cal(it[k], lef) &&
            cal(id, rig) >= cal(it[k], rig)) {
        it[k] = id;
        return;
    }
    int mid = (lef + rig) >> 1;
    if (cal(id, lef) <= cal(it[k], lef) &&
            cal(id, mid) <= cal(it[k], mid))
        down(mid + 1, rig, (k << 1) + 1, id);
    else
        if (cal(id, lef) >= cal(it[k], lef) &&
                cal(id, mid) >= cal(it[k], mid)) {
            down(mid + 1, rig, (k << 1) + 1, it[k]);
            it[k] = id;
        }
        else
            if (cal(id, mid + 1) <= cal(it[k], mid + 1) &&
                    cal(id, rig) <= cal(it[k], rig))
                down(lef, mid, k << 1, id);
            else
                if (cal(id, mid + 1) >= cal(it[k], mid + 1) &&
                        cal(id, rig) >= cal(it[k], rig)) {
                    down(lef, mid, k << 1, it[k]);
                    it[k] = id;
                }
}

void update(const int& lef, const int& rig,
        const int& u, const int& v,
        const int& k, const int& id) {
    if (lef == u && rig == v) {
        down(lef, rig, k, id);
        return;
    }
    int mid = (lef + rig) >> 1;
    if (v <= mid)
        update(lef, mid, u, v, k << 1, id);
    else
        if (u > mid)
            update(mid + 1, rig, u, v, (k << 1) + 1, id);
        else {
            update(lef, mid, u, mid, k << 1, id);
            update(mid + 1, rig, mid + 1, v, (k << 1) + 1, id);
        }
}

ll get(const int& lef, const int& rig,
        const int& k, const int& pos) {
    ll val = (it[k] == -1 ? -1 : cal(it[k], pos));
    if (lef == rig)
        return val;
    int id;
    int mid = (lef + rig) >> 1;
    if (pos <= mid)
        return max(val, get(lef, mid, k << 1, pos));
    else
        return max(val, get(mid + 1, rig, (k << 1) + 1, pos));
}

int main() {
    scanf("%d %d", &n, &m);
    memset(it, -1, n * 5 * sizeof(int));

    for (int i = 0; i < m; ++i) {
        scanf("%lld %lld %lld %lld",
            &data[i].s, &data[i].e,
            &data[i].v, &data[i].d);

        update(1, n, data[i].s, data[i].e, 1, i);
    }

    ll val;
    for (int i = 1; i <= n; ++i) {
        val = get(1, n, 1, i);
        printf("%lld\n", (val == -1 ? 0 : val));
    }

    return 0;
}
