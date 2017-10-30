#include <bits/stdc++.h>
using namespace std;

const int MAX = 110;

int t, n, u, v;
double w;
double x[MAX], y[MAX], dist[MAX];
int visited[MAX];

double distance(int i, int j){
	return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
			visited[i] = 0;
			dist[i] = -1;
		}

		priority_queue< pair<double, int>, vector< pair<double,int> >, greater< pair<double, int> > > pq;
		pq.push(make_pair(0, 0));
		dist[0] = 0;
		double result = 0;
		while (!pq.empty()){
			u = pq.top().second;
			w = pq.top().first;
			pq.pop();

			if (visited[u]) continue;
			visited[u] = true;
			result += w;
			for (int v = 0; v < n; v++){
				w = distance(u, v);
				if (!visited[v] && (dist[v] < 0 || dist[v] > w)){
					dist[v] = w;
					pq.push(make_pair(w, v));	
				}
			}
		}
		cout << fixed << setprecision(2) << result << "\n";
		if (t) cout << "\n";
	}

	return 0;
}