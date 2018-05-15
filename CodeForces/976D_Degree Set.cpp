#include <bits/stdc++.h>
using namespace std;

vector<int> deg;
int n;

void prepare() {
    int sum_deg = 0;
    int id = (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        sum_deg += deg[i];
    }

    int remain_vertices = deg[n - 1] + 1 - n;
    for (int i = 1; i < remain_vertices; i++) {
        deg.push_back(deg[id]);
        sum_deg += deg[id];
    }
    if ((sum_deg + deg[id]) & 1) {
        for (int i = 0; i < n; i++) {
            if ((sum_deg + deg[i]) % 2 == 0) {
                sum_deg += deg[i];
                deg.push_back(deg[i]);
                break;
            }
        }
    }
    else {
        deg.push_back(deg[id]);
        sum_deg += deg[id];
    }
    assert(sum_deg % 2 == 0);
}

void makeGraph() {
    priority_queue<pair<int, int>> pq;
    vector<pair<int, int>> list_edges;

    sort(deg.begin(), deg.end());
    for (int d: deg) {
        cout << d << " ";
    }
    return;
    for (int i = 0; i < deg.size(); i++) {
        pq.push(make_pair(deg[i], i + 1));
    }
    pair<int, int> u, v;
    vector<pair<int, int>> list_v;

    while (!pq.empty()) {
        u = pq.top();
        pq.pop();
        list_v.clear();

        for (int i = 0; i < u.first; i++) {
            assert(!pq.empty());
            v = pq.top();
            pq.pop();

            list_edges.push_back(make_pair(u.second, v.second));
            v.first--;
            if (v.first) {
                list_v.push_back(v);
            }
        }

        for (pair<int, int> v : list_v) {
            pq.push(v);
        }
    }

    assert(list_edges.size() <= 1e6);
    cout << list_edges.size() << "\n";
    for (pair<int, int> edge : list_edges) {
        cout << edge.first << " " << edge.second << "\n";
    }
}

int main() {
    freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int d, i = 0; i < n; i++) {
        cin >> d;
        deg.push_back(d);
    }

    prepare();
    makeGraph();

    return 0;
}