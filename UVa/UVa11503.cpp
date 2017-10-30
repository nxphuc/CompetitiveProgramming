#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5+10;

map<string,int> names;
int parent[MAX], num[MAX];
int cs, n, q, u, v;
string s, t;

int getIndex(string s){
	if (names.find(s) == names.end()){
		names[s] = ++n;
		parent[n] = n;
		num[n] = 1;
		return n;
	}
	return names[s];
}

int getSet(int u){
	while (u != parent[u])
		u = parent[u];
	return u;
}

int main(){
	ios::sync_with_stdio(false);

	cin >> cs;
	while (cs--){
		names.clear();
		n = 0;
		cin >> q;
		while (q--){
			cin >> s >> t;
			u = getIndex(s);
			v = getIndex(t);
			u = getSet(u);
			v = getSet(v);
			if (u != v){
				parent[v] = u;
				num[u] += num[v];
			}
			cout << num[u] << "\n";
		}

	}
	return 0;
}