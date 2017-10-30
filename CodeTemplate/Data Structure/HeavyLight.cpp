//http://codeforces.com/contest/696/problem/E
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pli;
const ll oo = 1e18;
const int MAX = 1e5 + 1;
int n, m, q, u, v, k, type;
int par[MAX], dep[MAX], sz[MAX];
int head[MAX], tail[MAX], ind[MAX], obj[MAX], nodeRes;
pli it[MAX * 5];
ll add[MAX * 5];
vector <int> adj[MAX], w[MAX], res;

void getSz(const int& u, const int& par = 0) {
    ::par[u] = par;
    sz[u] = 1;
    for (vector <int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it)
        if (*it != par) {
            dep[*it] = dep[u] + 1;
            getSz(*it, u);
            sz[u] += sz[*it];
        }
}

void buildHVL(const int& u, const int& head, const int& par = 0) {
    static int cnt = 0;
    obj[ind[u] = ++cnt] = u;
    ::head[u] = head;

    int nextPoint = 0;
    for (vector <int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it)
        if (*it != par && sz[nextPoint] < sz[*it])
            nextPoint = *it;

    if (nextPoint != 0)
        buildHVL(nextPoint, head, u);
    for (vector <int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it)
        if (*it != par && *it != nextPoint)
            buildHVL(*it, *it, u);

    tail[u] = cnt;
}

int LCA(int u, int v) {
    while (head[u] != head[v])
        if (dep[head[v]] > dep[head[u]])
            v = par[head[v]];
        else
            u = par[head[u]];

    return (dep[u] > dep[v] ? v : u);
}

void initIT(const int& lef = 1, const int& rig = n, const int& k = 1) {
    if (lef == rig) {
        it[k] = (w[obj[lef]].empty() ? pli(oo, 0) : pli(w[obj[lef]].back(), obj[lef]));
        return;
    }
    int mid = (lef + rig) >> 1;
    initIT(lef, mid, k << 1);
    initIT(mid + 1, rig, (k << 1) + 1);
    it[k] = min(it[k << 1], it[(k << 1) + 1]);
}

void erase(const int& lef, const int& rig, const int& pos, const int& k = 1) {
    if (lef == rig) {
        w[obj[lef]].pop_back();
        it[k] = (w[obj[lef]].empty() ? pli(oo, 0) : pli(w[obj[lef]].back(), obj[lef]));
        if (it[k].second != 0)
            it[k].first += add[k];
        return;
    }
    int mid = (lef + rig) >> 1;
    if (pos <= mid)
        erase(lef, mid, pos, k << 1);
    else
        erase(mid + 1, rig, pos, (k << 1) + 1);
    it[k] = min(it[k << 1], it[(k << 1) + 1]);
    if (it[k].second != 0)
        it[k].first += add[k];
}

pli getIT(const int& lef, const int& rig, const int& u, const int& v, const int& k = 1) {
    if (lef == u && rig == v)
        return it[k];
    int mid = (lef + rig) >> 1;
    pli res;
    if (v <= mid)
        res = getIT(lef, mid, u, v, k << 1);
    else
        if (u > mid)
            res = getIT(mid + 1, rig, u, v, (k << 1) + 1);
        else
            res = min(getIT(lef, mid, u, mid, k << 1), getIT(mid + 1, rig, mid + 1, v, (k << 1) + 1));
    if (res.second != 0)
        res.first += add[k];
    return res;
}

ll getRes(int u, int v) {
    pli res(oo, 0);
    int parCommon = LCA(u, v);

    while (head[u] != head[parCommon]) {
        res = min(res, getIT(1, n, ind[head[u]], ind[u]));
        u = par[head[u]];
    }
    if (ind[u] >= ind[parCommon])
        res = min(res, getIT(1, n, ind[parCommon], ind[u]));

    while (head[v] != head[parCommon]) {
        res = min(res, getIT(1, n, ind[head[v]], ind[v]));
        v = par[head[v]];
    }
    if (ind[v] >= ind[parCommon])
        res = min(res, getIT(1, n, ind[parCommon], ind[v]));

    if (res.second != 0) {
        int pos = w[res.second].back();
        erase(1, n, ind[res.second]);
        return pos;
    }
    return -1;
}

void upIT(const int& lef, const int& rig, const int& u, const int& v, const int& k = 1) {
    if (lef == u && rig == v) {
        it[k].first += ::k;
        add[k] += ::k;
        return;
    }
    int mid = (lef + rig) >> 1;
    if (v <= mid)
        upIT(lef, mid, u, v, k << 1);
    else
        if (u > mid)
            upIT(mid + 1, rig, u, v, (k << 1) + 1);
        else {
            upIT(lef, mid, u, mid, k << 1);
            upIT(mid + 1, rig, mid + 1, v, (k << 1) + 1);
        }
        it[k] = min(it[k << 1], it[(k << 1) + 1]);
        it[k].first += add[k];
}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    getSz(1);
    buildHVL(1, 1);

    for (int i = 1; i <= m; ++i) {
        scanf("%d", &u);
        w[u].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        sort(w[i].begin(), w[i].end());
        reverse(w[i].begin(), w[i].end());
    }
    initIT();

    while (q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d %d", &u, &v, &k);
            res.clear();
            while (k-- && (nodeRes = getRes(u, v)) != -1)
                res.push_back(nodeRes);
            printf("%d", res.size());
            for (vector <int>::iterator it = res.begin(); it != res.end(); ++it)
                printf(" %d", *it);
            printf("\n");
        }
        else {
            scanf("%d %d", &u, &k);
            upIT(1, n, ind[u], tail[u]);
        }
    }

    return 0;
}
