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

string nextString(int id){
	string s = "";
	while (id){
		if (id > 26){
			id -= 26;
			s += "a";
		}
		else{
			s += char('a' + id - 1);
			id = 0;
		}
	}
	return s;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, k, id = 0;
	vector<string> a;
	string s;

	cin >> n >> k;
	a.assign(n, "");
	for (int i = 0; i < n-k+1; i++){
		cin >> s;
		if (s == "YES"){
			if (a[i] != "")
				continue;
			else
				a[i] = nextString(++id);
		}
		else{
			if (a[i] != "")
				a[i+k-1] = a[i];
			else
				a[i] = a[i+k-1] = nextString(++id);
		}
	}

	REP(i,0,n)
		if (a[i] == "")
			a[i] = nextString(++id);
	REP(i,0,n){
		a[i][0] -= 32;
		cout << a[i] << " ";
	}

	return 0;
}