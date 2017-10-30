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

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	string s, t;
	map<char, char> mymap;

	cin >> s >> t;
	REP(i,0,s.length()){
		if (mymap.find(s[i]) == mymap.end() && mymap.find(t[i]) == mymap.end()){
			mymap[s[i]] = t[i];
			mymap[t[i]] = s[i];
		}
		else
			if (mymap[s[i]] != t[i]){
				cout << -1;
				return 0;
			}
	}

	set< pair<char, char> > myset;
	for(map<char, char>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		if (it->fi != it->se)
		{
			pair<char, char> p(min(it->fi, it->se), max(it->fi, it->se));
			myset.insert(p);
		}
	}

	cout << myset.size() << "\n";
	for (set< pair<char, char> >::iterator it = myset.begin(); it != myset.end(); it++)
		cout << it->fi << " " << it->se << "\n";

	return 0;
}