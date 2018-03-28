#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10;

vector<int> adj[MAX];
int num[MAX], low[MAX];
int in_graph[MAX];
int t, n, m, u, v;
int cnt;
int count_scc;
stack<int> st;

int tarjan(int u){
	low[u] = num[u] = ++cnt;
    st.push(u);
	for (int v: adj[u]){
        if (in_graph[v]) {
            if (num[v]) {
                low[u] = min(num[v], low[u]);
            }
            else {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }
        }
	}

	if (num[u] == low[u]) {
        count_scc++;
        int v;
        do {
            v = st.top();
            st.pop();
            in_graph[v] = false;
        } while (u != v);
    }
	return 0;
}

int main(){
    // freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			adj[i].clear();
			low[i] = num[i] = 0;
            in_graph[i] = 1;
		}
		for (int i = 0; i < m; i++){
			cin >> u >> v;
			adj[u].push_back(v);
		}

        count_scc = cnt = 0;
		for (int i = 1; i <= n; i++)
			if (!num[i]){
				tarjan(i);
			}
        cout << (count_scc != n ? "SIM\n" : "NAO\n");
    }
	return 0;
}