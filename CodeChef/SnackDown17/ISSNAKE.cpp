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

int t, n;
string s[2];

int isValid(int i, int j){
	for (; j < n; j++)
		if (s[i][j] == '#' && s[(i + 1) % 2][j] == '#')
			i ^= 1;
		else
			if (s[i][j] == '.')
				break;
	for (; j < n; j++)
		if (s[i][j] == '#' || s[(i + 1) % 2][j] == '#')
			return false;
	return true;
}

int solve(){
	int i = 0;
	while (i < n && s[0][i] == '.' && s[1][i] == '.')
		i++;
	if (s[0][i] == '#' && isValid(0, i))
		return 1;
	if (s[1][i] == '#' && isValid(1, i))
		return true;
	return false;
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n;
		REP(i,0,2)
			cin >> s[i];

		cout << (solve() ? "yes\n" : "no\n");
	}

	return 0;
}