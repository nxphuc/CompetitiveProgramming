#include <algorithm>
#include <vector>
using namespace std;

struct Hungary {
    const int oo = 1e9;
    int n, m, **cost, *fx, *fy, *matx, *which, *dis;
    bool *used;

    Hungary(int n, int m) : n(n), m(m) {
        which = new int[m + 1];
        dis = new int[m + 1];

        fx = new int[n + 1];
        memset(fx, 0, (n + 1) * sizeof(int));
        fy = new int[m + 1];
        memset(fy, 0, (m + 1) * sizeof(int));

        used = new bool[m + 1];
        memset(used, false, (m + 1) * sizeof(bool));
        matx = new int[m + 1];
        memset(matx, 0, (m + 1) * sizeof(int));

        cost = new int*[n + 1];
        for (int i = 0; i <= n; ++i) {
            cost[i] = new int[m + 1];
            for (int j = 0; j <= m; ++j)
                cost[i][j] = oo;
        }
    }

    void add(int x, int y, int c){
        cost[x][y] = min(cost[x][y], c);
    }

    int mincost() {
        for (int x = 1; x <= n; ++x) {
            int u = 0; matx[0] = x;
            for (int y = 0; y <= m; ++y) {
                dis[y] = oo + 1;
                used[y] = false;
            }

            do {
                used[u] = true;
                int x0 = matx[u], delta = oo + 1, v;

                for (int y = 1; y <= m; ++y)
                    if (!used[y]) {
                        int curdis = cost[x0][y] - fx[x0] - fy[y];
                        if (curdis < dis[y]) {
                            dis[y] = curdis;
                            which[y] = u;
                        }

                        if (dis[y] < delta) {
                            delta = dis[y];
                            v = y;
                        }
                    }

                for (int y = 0; y <= m; ++y)
                    if (used[y]) {
                        fx[matx[y]] += delta;
                        fy[y] -= delta;
                    }
                    else
                        dis[y] -= delta;

                u = v;
            } while (matx[u] != 0);

            do {
                int v = which[u];
                matx[u] = matx[v];
                u = v;
            } while (u);
        }

        int res = 0;
        for (int y = 1; y <= m; ++y)
            if (cost[matx[y]][y] < oo)
                res += cost[matx[y]][y];

        return res;
    }
};
