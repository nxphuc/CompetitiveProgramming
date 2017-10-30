#include <bits/stdc++.h>
using namespace std;

const int MAX = 510;
const int INF = 1e9;

vector< pair<int,int> > adj[MAX];
int n, u, v, w, q;
int dist[MAX];

void dijkstra(int s){
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int, int> > > pq;

	for (int i = 0; i <= 500; i++)
		dist[i] = INF;
	dist[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()){
		w = pq.top().first;
		u = pq.top().second;
		pq.pop();
		
		if (w != dist[u])
			continue;
		for (pair<int,int> e : adj[u])
			if (dist[e.first] > w + e.second){
				dist[e.first] = w + e.second;
				pq.push(make_pair(dist[e.first], e.first)); 
			}
	}
}

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> n;
	while (n--){
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	cin >> u;
	dijkstra(u);
	cin >> q;
	while (q--){
		cin >> v;
		if (dist[v] < INF)
			cout << dist[v] << "\n";
		else
			cout << "NO PATH\n";
	}
	return 0;
}