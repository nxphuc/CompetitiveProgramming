#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> deg;
vector<pair<int, int>> graph;
int n;

void buildGraph() {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i].first == 1) {
            q.push(deg[i].second);
        }
        else {
            pq.push(deg[i]);
        }
    }
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        while (tmp.first > 1) {
            cout << tmp.second << " " << q.front() << "\n";
            q.pop();
            tmp.first--;
        }
        q.push(tmp.second);
    }
    int u = q.front();
    q.pop();
    cout << u << " " << q.front() << "\n";
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int m;
    cin >> n >> m;

    deg.resize(n);
    for (int i = 0; i < n; i++) {
        deg[i] = make_pair(0, i);
    }
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        deg[u].first++;
        deg[v].first++;
    }

    sort(deg.begin(), deg.end());
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + deg[i].first + n - cnt - 1 <= 2 * n - 2) {
            sum += deg[i].first;
            cnt++;
        }
        else {
            break;
        }
    }
    int remain = 2 * n - 2 - sum;
    for (int i = cnt; i < n; i++) {
        deg[i].first = (i < n - 1 ? 1 : remain);
        remain--;
    }

    cout << n - cnt << "\n" << n << " " << n-1 << "\n";
    buildGraph();

    return 0;
}