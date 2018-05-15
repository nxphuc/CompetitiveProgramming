#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

vector<int> quar[MAX];
int a[MAX], b[MAX];
int n, k;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i - 1] = a[i];
    }
    for (int u, v, i = 0; i < k; i++) {
        cin >> u >> v;
        quar[u].push_back(v);
        quar[v].push_back(u);
    }
    sort(b, b + n);
    for (int i = 1; i <= n; i++) {
        int cnt = lower_bound(b, b + n, a[i]) - b;
        for (int v : quar[i]) {
            cnt -= a[v] < a[i];
        }
        cout << cnt << " ";
    }

    return 0;
}