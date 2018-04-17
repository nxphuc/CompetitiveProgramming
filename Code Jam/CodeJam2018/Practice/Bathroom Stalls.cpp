#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    ll min_dist, max_dist, num;

    Node (ll min_dist = 0, ll max_dist = 0, ll num = 0) : min_dist(min_dist), max_dist(max_dist), num(num) {}

    bool operator<(const Node& other) const {
        if (min_dist != other.min_dist) {
            return min_dist > other.min_dist;
        }
        return max_dist > other.max_dist;
    }
};

Node createNode(ll dist) {
    ll max_dist = dist / 2;
    ll min_dist = max_dist - ((dist & 1) ? 0 : 1);
    return Node(min_dist, max_dist);
}

void doTestcase() {
    map<Node, ll> map_cnt;

    ll n, k;
    cin >> n >> k;

    map_cnt[createNode(n)] = 1;
    while (1) {
        Node tmp = map_cnt.begin()->first;
        ll cnt = map_cnt.begin()->second;
        map_cnt.erase(tmp);
        k -= cnt;
        if (k <= 0) {
            cout << tmp.max_dist << " " << tmp.min_dist << "\n";
            return;
        }
        map_cnt[createNode(tmp.max_dist)] += cnt;
        map_cnt[createNode(tmp.min_dist)] += cnt;
    }
}

int main() {
    freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        doTestcase();
    }

    return 0;
}