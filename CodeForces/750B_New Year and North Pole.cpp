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

	int mx = -inf;
	int mn = inf;
	int cur = 0;
	int n, t;
	string dir;

	cin >> n;
	while (n--){
		cin >> t >> dir;

		if (dir == "South"){
			cur -= t;
			mn = min(mn, cur);
		}
		else
			if (dir == "North"){
				cur += t;
				mx = max(mx, cur);
			}
		else
			if (cur == 0 || cur == -20000){
				cout << "NO";
				return 0;
			}

		if (cur > 0 || cur < -20000){
			cout << "NO";
			return 0;
		}
	}

	cout << (cur ? "NO" : "YES");

	return 0;
}