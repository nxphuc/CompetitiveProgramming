/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 1e3 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dist[MAX];
vi adj[MAX];
map<string,int> mymap;
int n, v;
string s[3];

void bfs(int s){
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()){
		s = q.front();
		q.pop();
		for (int i = 0; i < adj[s].size(); i++)
			if (dist[adj[s][i]] == -1){
				dist[adj[s][i]] = dist[s]+1;
				q.push(adj[s][i]);
			}
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	memset(dist,-1,sizeof(dist));
	cin >> n;
	while (n--){
		REP(i,0,3){
			cin >> s[i];
			if (mymap.find(s[i]) == mymap.end())
				mymap[s[i]] = ++v;
		}
		REP(i,0,3)
			REP(j,0,3)
				if (i == j)
					continue;
				else
					adj[mymap[s[i]]].pb(mymap[s[j]]);
	}

	bfs(mymap.find("Isenbaev") == mymap.end() ? 0 : mymap["Isenbaev"]);
	for (map<string,int>::iterator it = mymap.begin(); it != mymap.end(); it++){
		cout << it->first << " ";
		if (dist[it->second] == -1)
			cout << "undefined\n";
		else
			cout << dist[it->second] << "\n";
	}

	return 0;
}