#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e13;
const int N = 101;
const long long ASSERT_RANGE = 1LL << 30LL;

int n, q;
long long dist[N][N], a[N][N];
bool neg[N][N];
string name[N];
int line_count = 0;
int num_error = 0;

void findPath(int s) {
    for (int i = 0; i < n; i++) {
        dist[s][i] = INF;
        neg[s][i] = false;
    }

    dist[s][s] = a[s][s];

    for (int step = 1; step <= n; step++) {
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if ((u == v || a[u][v]) && dist[s][u] != INF && dist[s][v] > dist[s][u] + a[u][v]) {
                    if (step == n)
                        neg[s][v] = true;
                    dist[s][v] = dist[s][u] + a[u][v];
                }
    }
}

void process() {
    if (!(1 <= n && n <= 100)) {
        cerr << line_count << " n: " << n << "\n";
        num_error++;
    }
    // assert(1 <= n && n <= 100);
    for (int i = 0; i < n; i++) {
        line_count++;
        cin >> name[i];
        if (!(name[i].length() <= 20)) {
            cerr << line_count << " string length: " << name[i] << " " << name[i].length() << "\n";
            num_error++;
        }
        // assert(name[i].length() <= 20);

        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (!(-ASSERT_RANGE <= a[i][j] && a[i][j] <= ASSERT_RANGE)) {
                cerr << line_count << " value " << i << " " << j << " " << a[i][j] << "\n";
                num_error++;
                // exit(0);
            }
            // assert(-ASSERT_RANGE <= a[i][j] && a[i][j] <= ASSERT_RANGE);
        }

        if (a[i][i] > 0)
            a[i][i] = 0;
        if (a[i][i] < 0)
            a[i][i] = -INF;
    }

    for (int s = 0; s < n; s++)
        findPath(s);

    cin >> q;
    line_count++;
    if (!(1 <= q && q <= n*n)) {
        cerr << line_count << " " << "query error: " << q << " " << n << "\n";
        num_error++;
    }
    // assert(1 <= q && q <= n*n);

    while (q--) {
        int u, v;
        cin >> u >> v;
        line_count++;
        if (!(0 <= u && u < n)) {
            cerr << line_count << " " << " query u error: " << u << " " << n << "\n";
            num_error++;
        }
        if (!(0 <= v && v < n)) {
            cerr << line_count << " " << " query v error: " << v << " " << n << "\n";
            num_error++;
        }
        // assert(0 <= u && u < n);
        // assert(0 <= v && v < n);

        if (neg[u][v])
            cout << "NEGATIVE CYCLE\n";
        else {
            cout << name[u] << "-" << name[v] << " ";

            if (dist[u][v] == INF)
                cout << "NOT REACHABLE\n";
            else
                cout << dist[u][v] << endl;
        }
    }
}
int main() {
    for (int tc = 1;; tc++) {
        cin >> n;
        line_count++;

        if (!n)
            break;

        cout << "Case #" << tc << ":\n";
        process();
    }
    if (num_error > 0) {
        cout << num_error;
    }
}
