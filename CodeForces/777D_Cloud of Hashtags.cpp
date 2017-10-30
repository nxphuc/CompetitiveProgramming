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

string s[MAX];
int n;

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	FOR(i,1,n){
		cin >> s[i];
		// s[i].erase(0, 1);
	}

	int cur = s[n].length();
	for (int i = n-1; i > 0; i--){
		int j = 0;
		while (j < s[i].length() && j < cur && s[i][j] == s[i+1][j])
			j++;
		if (j == cur)
			s[i].erase(cur, s[i].length() - cur);
		else
			if (j == s[i].length() || s[i][j] < s[i+1][j])
				cur = s[i].length();
			else{
				s[i].erase(j, s[i].length() - j);
				cur = j;
			}
	}
	FOR(i,1,n)
		cout << s[i] << "\n";

	return 0;
}