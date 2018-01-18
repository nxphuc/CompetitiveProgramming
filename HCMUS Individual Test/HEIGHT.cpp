#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1e5 + 10;
const int INF = 1e9;

struct Node {
	int des, hei;
	ll len;

	Node(int des = 0, int hei = 0, ll len = 0)
		: des(des), hei(hei), len(len)
	{
	}

	int operator<(const Node& rth) const {
		return hei < rth.hei || (hei == rth.hei && len > rth.len);
	}
};

vector<Node> adj[MAX];
ll dist[MAX];
int n, m;

void dijkstra(int s, int minHei) {
	priority_queue< pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pair<ll, int> tmp;
	for (int i = 1; i <= n; i++) {
		dist[i] = -1;
	}

	pq.push(make_pair(0, s));
	dist[s] = 0;
	
	while (!pq.empty()) {
		tmp = pq.top();
		pq.pop();

		if (tmp.first != dist[tmp.second]) {
			continue;
		}
		s = tmp.second;
		for (auto& v : adj[s]) {
			if (v.hei < minHei) {
				continue;
			}
			if (dist[v.des] == -1 || dist[v.des] > dist[s] + v.len) {
				dist[v.des] = dist[s] + v.len;
				pq.push(make_pair(dist[v.des], v.des));
			}
		}
	}
}

int main() {
	freopen("HEIGHT.INP", "rt", stdin);
	freopen("HEIGHT.OUT", "wt", stdout);
	ios::sync_with_stdio(false);

	int s, t, u, v, h, d;
	int minHei = 1, maxHei = INF;
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> h >> d;
		adj[u].push_back(Node(v, h, d));
		adj[v].push_back(Node(u, h, d));
	}
	pair<ll, int> res = make_pair(-1, -1);

	while (minHei <= maxHei) {
		ll midHei = (minHei + maxHei) / 2;
		dijkstra(s, midHei);
		if (dist[t] != -1) {
			res = make_pair(midHei, dist[t]);
			minHei = midHei + 1;
		}
		else {
			maxHei = midHei - 1;
		}
	}
	cout << res.first << "\n" << res.second;

	return 0;
}