#include <bits/stdc++.h>
using namespace std;

const int MAX = 40;
const double EPS = 1e-9;

struct Edge {
	int u;
	int v;
	double w;

	Edge(int u = 0, int v = 0, double w = 0) : u(u), v(v), w(w) {}
};

string currencies[MAX];
vector<Edge> edges;
double dist[MAX];
int n, m;

int findCurrency(string s){
	for (int i = 0; i < n; i++)
		if (currencies[i] == s)
			return i;
	return -1;
}

int hasNegCycle(int s){
	memset(dist, 0, sizeof(dist));
	int u, v;
	double w;

	dist[s] = 1;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			u = edges[j].u;
			v = edges[j].v;
			w = edges[j].w;

			if (dist[v] < dist[u]*w)
				dist[v] = dist[u]*w;
		}
	}
	return dist[s] - 1 >= EPS;
}

int main(){
	ios::sync_with_stdio(false);

	int flag, cs = 0;
	string u, v;
	double w;

	while (1){
		cin >> n;

		if (!n)
			break;

		cs++;
		edges.clear();

		for (int i = 0; i < n; i++)
			cin >> currencies[i];
		cin >> m;
		for (int i = 0; i < m; i++){
			cin >> u >> w >> v;
			edges.push_back(Edge(findCurrency(u), findCurrency(v), w));
		}

		flag = 0;
		for (int i = 0; i < n; i++){
			if (hasNegCycle(i)){
				flag = 1;
				break;
			}
		}
		cout << "Case " << cs << ": " << (flag ? "Yes" : "No") << "\n";
	}

	return 0;
}