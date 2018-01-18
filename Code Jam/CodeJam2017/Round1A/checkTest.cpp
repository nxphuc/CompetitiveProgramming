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
	ifstream is1("B-small-attempt0.ou", ifstream::in);
	ifstream is2("B-small-attempt0_2.ou", ifstream::in);
	ios::sync_with_stdio(false);

	string s, t;

	REP(i,0,100){
		getline(is1, s);
		getline(is2, t);
		if (s != t){
			cout << i+1 << " " << s << " " << t << "\n";
			return 0;
		}
	}
	cout << "pass";

	return 0;
}