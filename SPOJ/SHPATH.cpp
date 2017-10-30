#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4+10;
const int INF = 1e9+10;

string names[MAX];
vector< pair<int,int> > adj[MAX];
int dist[MAX];
int t, n, m, u, v, w, q;
string src, des;

void dijkstra(int src){
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
	int u, w;
	pair<int,int> tmp;

	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty()){
		tmp = pq.top();
		pq.pop();
		w = tmp.first;
		u = tmp.second;
		if (dist[u] != w) continue;
		for (auto e : adj[u]){
			if (dist[e.first] > w + e.second){
				dist[e.first] = w + e.second;
				pq.push(make_pair(dist[e.first], e.first));
			}
		}
	}
}

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			adj[i].clear();
			dist[i] = INF;

			cin >> names[i];
			cin >> m;
			while (m--){
				cin >> v >> w;
				adj[i].push_back(make_pair(v, w));
			}
		}

		cin >> q;
		while (q--){
			cin >> src >> des;
			u = v = -1;
			for (int i = 1; i <= n; i++)
				if (src == names[i]){
					u = i;
					break;
				}
			for (int i = 1; i <= n; i++)
				if (des == names[i]){
					v = i;
					break;
				}
			dijkstra(u);
			cout << dist[v] << "\n";
		}
	}

	return 0;
}