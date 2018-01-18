#include <bits/stdc++.h> 


using namespace std;
typedef long long ll;  

const int N = 1009; 
const ll MOD = (ll)1e9 + 7ll; 
priority_queue <pair <long long, int> > Q;

ll cou[N]; 
ll c[N][N]; 
ll d[N];
int id[N];
int n, s, t;   
bool vis[N];

bool cmp(int x, int y) {
	return d[x] < d[y];
}

ll dijkstra(int s, int t) { 
	while (!Q.empty()) Q.pop();  
	for (int i = 1; i <= n; i++) {
		cou[i] = 0; 
		d[i] = (long long)(1e15); 
		id[i] = i;
	}
	Q.push(make_pair(0, s)); 
	d[s] = 0; 
	cou[s] = 1; 

	while (!Q.empty()) { 
		int u = Q.top().second;  
		Q.pop(); 
		if (vis[u]) continue;
		vis[u] = 1;
		// cout << u <<' '<< cou[u] <<endl; 
		for (int v = 1; v <= n; v++) if (c[u][v])  {
			// cout << 
			if (d[v] > d[u] + c[u][v]) {
				// cout <<v <<endl; 
				d[v] = d[u] + c[u][v]; 
				Q.push(make_pair(-d[v], v)); 
			}
		}
	}

	sort(id + 1, id + n + 1, cmp);
	cou[s] = 1;
	for (int i = 1; i <= n; i++) {
		int u = id[i];
		for (int v = 1; v <= n; v++) {
			if (c[u][v] > 0 && d[u] + c[u][v] == d[v]) {
				cou[v] = (cou[v] + cou[u]) % MOD;
			}
		}
	}
	return cou[t]; 
}

int main () { 

	// freopen("input", "r", stdin); 


	scanf("%d %d %d", &n, &s, &t); 


	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) { 

			scanf("%lld", &c[i][j]); 
		}
	printf("%lld", dijkstra(s, t)); 
}
