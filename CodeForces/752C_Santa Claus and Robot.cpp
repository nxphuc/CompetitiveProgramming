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

	int dirX = 0, dirY = 0;
	int n;
	string s;
	int res = 0;

	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++){
		switch (s[i]){
			case 'L':
				if (dirY == 1)
					dirX = 0, res++;
				dirY = -1;
				break;
			case 'R':
				if (dirY == -1)
					dirX = 0, res++;
				dirY = 1;
				break;
			case 'U':
				if (dirX == -1)
					dirY = 0, res++;
				dirX = 1;
				break;
			case 'D':
				if (dirX == 1)
					dirY = 0, res++;
				dirX = -1;
				break;
		}
		// cout << s[i] << " " << res << "\n";
	}

	cout << res+1;

	return 0;
}