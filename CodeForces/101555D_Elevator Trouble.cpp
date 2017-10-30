#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;

int dist[MAX];

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	memset(dist, -1, sizeof(dist));
	int f, s, g, u, d;

	cin >> f >> s >> g >> u >> d;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		s = q.front();
		q.pop();
		if (s + u <= f && dist[s + u] == -1) {
			dist[s + u] = dist[s] + 1;
			q.push(s + u);
		}
		if (s - d > 0 && dist[s - d] == -1) {
			dist[s - d] = dist[s] + 1;
			q.push(s - d);
		}
	}
	if (dist[g] == -1) {
		cout << "use the stairs";
	}
	else {
		cout << dist[g];
	}

	return 0;
}