#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

const int MAX = (8000 << 1) + 1;
int n, nn, m, u, v, cnt, low[MAX], num[MAX],
cntCpn, cpn[MAX], cache[MAX], cntCache, res[MAX];

bool fr[MAX], avail[MAX];
vector <int> adj[MAX], adjTmp[MAX],

adjDag[2][MAX], detail[MAX];
stack <int> st;

int negative(const int& u) {
    return (u > nn ? u - nn : u + nn);
}

void visit1(const int& u, const int& dad) {
    st.push(u);
    low[u] = num[u] = ++cnt;
    avail[u] = false;
    for (int i = 0; i < adj[u].size(); ++i)
    if (fr[adj[u][i]]) {
        if (avail[adj[u][i]]) {
            visit1(adj[u][i], u);
            low[u] = min(low[u], low[adj[u][i]]);
        }
        else
            low[u] = min(low[u], num[adj[u][i]]);
    }
    else
        if (cpn[adj[u][i]])
            adjTmp[u].push_back(cpn[adj[u][i]]);

    if (low[u] >= num[u]) {
        ++cntCpn;
        if (dad)
            adjTmp[dad].push_back(cntCpn);
        do {
            cpn[v = st.top()] = cntCpn;
            fr[v] = false;
            detail[cntCpn].push_back(v);

            for (int i = 0; i < adjTmp[v].size(); ++i)
                adjDag[0][cntCpn].push_back(adjTmp[v][i]);
            st.pop();
        } while (v != u);
    }
}

void visit2(const int& u) {
    fr[u] = false;
    for (int i = 0; i < adjDag[0][u].size(); ++i)
        if (fr[adjDag[0][u][i]])
            visit2(adjDag[0][u][i]);
    cache[cntCache++] = u;
}

int main() {
    scanf("%d %d", &m, &n);
    nn = n;
    memset(fr + 1, false, n <<= 1);
    memset(avail + 1, false, n);

    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        if (u < 0)
            u = negative(abs(u));
        if (v < 0)
            v = negative(abs(v));

        avail[u] = fr[u] = true;
        avail[negative(u)] = fr[negative(u)] = true;
        avail[v] = fr[v] = true;
        avail[negative(v)] = fr[negative(v)] = true;

        adj[negative(u)].push_back(v);
        adj[negative(v)].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        if (fr[i])
            visit1(i, 0);

    for (int i = 1; i <= nn; ++i)
        if (cpn[i] && cpn[i] == cpn[negative(i)]) {
            printf("NO");
            return 0;
        }

    memset(fr + 1, true, cntCpn);
    for (int i = 1; i <= cntCpn; ++i)
        for (int j = 0; j < adjDag[0][i].size(); ++j)
            adjDag[1][adjDag[0][i][j]].push_back(i);
    for (int i = 1; i <= cntCpn; ++i)
        if (adjDag[1][i].size() == 0)
            visit2(i);

    for (int i = 0; i < cntCache; ++i)
        if (res[u = cache[i]] == 0) {
            res[u] = 1;
            for (int j = 0; j < detail[u].size(); ++j)
                res[cpn[negative(detail[u][j])]] = -1;
        }
        else
            for (int j = 0; j < adjDag[1][u].size(); ++j)
                res[adjDag[1][u][j]] = -1;

    m = 0;
    for (int i = 1; i <= nn; ++i)
        if (res[cpn[i]] == 1)
            ++m;

    printf("YES\n%d\n", m);
    for (int i = 1; i <= nn; ++i)
        if (res[cpn[i]] == 1)
            printf("%d ", i);

    return 0;
}
