#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > a, graph;
vector<int> matchR, matchC, maxR, maxC;
vector<bool> seen;
int n, m;
long long res;

int findMatch(int i){
	for (int j = 0; j < m; j++)
		if (graph[i][j] && !seen[j]){
			seen[j] = true;
			if (matchC[j] == -1 || findMatch(matchC[j])){
				matchR[i] = j;
				matchC[j] = i;
				return true;
			}
		}
	return false;
}

int bipartiteMatching(){
	matchR.assign(n, -1);
	matchC.assign(m, -1);

	for (int i = 0; i < n; i++){
		seen.assign(m, false);
		findMatch(i);
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	a.assign(n, vector<int>(m));
	graph.assign(n, vector<int>(m, 0));
	maxR.assign(n, -1);
	maxC.assign(m, -1);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			maxR[i] = max(maxR[i], a[i][j]);
			maxC[j] = max(maxC[j], a[i][j]);
			res += a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
		res -= maxR[i];
	for (int j = 0; j < m; j++)
		res -= maxC[j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (maxR[i] == maxC[j])
				graph[i][j] = 1;

	bipartiteMatching();
	for (int i = 0; i < n; i++)
		if (matchR[i] != -1)
			res += maxR[i];
	cout << res;
	
	return 0;
}