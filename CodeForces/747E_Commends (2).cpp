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

string s;
vector< vector<string> > f;

void process(int &id, int depth){
	depth++;
	string t = "";
	for (id; id < s.length(); id++)
		if (s[id] == ',')
			break;
		else
			t += s[id];
	id++;

	int numChild = 0;
	for (id; id < s.length(); id++)
		if (s[id] == ',')
			break;
		else
			numChild = numChild * 10 + (s[id] - '0');
	id++;

	// cout << "@@ " << t << " " << numChild << " " << depth << "\n";

	if (depth > f.size()){
		vector<string> tmp;
		tmp.push_back(t);
		f.push_back(tmp);
	}
	else
		f[depth - 1].push_back(t);
	for (int i = 0; i < numChild; i++)
		process(id, depth);
}


int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> s;
	// cout << s << "\n";
	int pos = 0;
	while (pos < s.length())
		process(pos, 0);
	cout << f.size() << "\n";
	for (int i = 0; i < f.size(); i++){
		for (int j = 0; j < f[i].size(); j++)
			cout << f[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
