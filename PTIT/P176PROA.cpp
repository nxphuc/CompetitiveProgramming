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

string decToString(int num){
	string s = "";
	while (num){
		s = (char)(97 + (num-1) % 26) + s;
		num = (num-1)/26;
	}
	return s;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n;
	string s;
	set<string> lst;

	cin >> n;
	while (n--){
		cin >> s;
		REP(i,0,s.length())
			REP(j,0,s.length())
				lst.insert(s.substr(i, j-i+1));
	}

	int cur = 0;
	s = "1";
	do{
		s = decToString(++cur);
		// cout << cur << " " << s << "\n";
	} while (lst.find(s) != lst.end());
	cout << s;

	return 0;
}