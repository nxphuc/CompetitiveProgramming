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

const int MAX = 1e6 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, m, q, type;
int u, v;
string s, t;
map<string, int> wordList;
int rev[MAX];
int f[MAX];
int cnt;

int getRoot(int u){
	return f[u] = (f[u] == u ? u : getRoot(f[u]));
}

int isOpposite(int u, int v){
	int pu = getRoot(u);
	int pv = getRoot(v);

	if (pu == pv)
		return 0;
	if (rev[pu] == -1 && rev[pv] == -1)
		return 0;
	if (rev[pu] != -1 && getRoot(rev[pu]) == pv)
		return 1;
	if (rev[pv] != -1 && getRoot(rev[pv]) == pu)
		return 1;
	return 0;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m >> q;
	REP(i,0,n){
		cin >> s;
		++cnt;
		wordList[s] = cnt;
		rev[cnt] = -1;
		f[cnt] = cnt;
	}
	REP(i,0,m){
		cin >> type >> s >> t;
		u = wordList[s];
		v = wordList[t];
		// if (wordList.count(s))
		// 	u = wordList[s];
		// else{
		// 	u = wordList[s] = ++cnt;
		// 	f[u] = u;
		// }
		// if (wordList.count(t))
		// 	v = wordList[t];
		// else{
		// 	v = wordList[t] = ++cnt;
		// 	f[v] = v;
		// }

		if (type == 1){
			if (isOpposite(u, v)){
				cout << "NO\n";
			}
			else{
				cout << "YES\n";
				u = getRoot(u);
				v = getRoot(v);
				if (u == v)
					continue;
				f[v] = u;

				if (rev[u] != -1 && rev[v] != -1){
					int ru = getRoot(rev[u]);
					int rv = getRoot(rev[v]);
					f[rv] = ru;
					rev[u] = ru;
					rev[ru] = u;
				}
				else{
					int ru = (rev[u] != -1 ? rev[u] : rev[v]);
					rev[u] = ru;
					if (ru != -1)
						rev[ru] = u;
				}
			}
		}
		else{
			u = getRoot(u);
			v = getRoot(v);
			if (u == v){
				cout << "NO\n";
			}
			else{
				cout << "YES\n";
				if (rev[u] != -1){
					int ru = getRoot(rev[u]);
					if (ru != v)
						f[ru] = v;
				}
				if (rev[v] != -1){
					int rv = getRoot(rev[v]);
					if (rv != u)
						f[rv] = u;
				}

				rev[v] = u;
				rev[u] = v;
			}
		}
	}
	while (q--){
		cin >> s >> t;
		u = getRoot(wordList[s]);
		v = getRoot(wordList[t]);
		if (u == v)
			cout << "1\n";
		else
			if (rev[u] != -1 && rev[v] != -1 && (getRoot(rev[u]) == getRoot(v)) || (getRoot(rev[v]) == getRoot(u)))
				cout << "2\n";
			else
				cout << "3\n";
	}

	return 0;
}