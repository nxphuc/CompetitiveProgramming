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

string solve(string s, int n){
	string t = s;
	sort(t.begin(), t.end());
	if (s == t)
		return s;
	t = string(n, '1');
	if (t > s)
		return string(n-1, '9');
	int i = 0;
	while (i < n){
		if (s[i] > s[i+1]){
			while (i > 0 && s[i] == s[i-1]) i--;
			s[i]--;
			REP(j,i+1,n)
				s[j] = '9';
			return s;
		}
		i++;
	}
	return t;
}

int main(){
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int T, n;
	string s;

	cin >> T;
	FOR(cs,1,T){
		cin >> s;
		n = s.length();
		cout << "Case #" << cs << ": " << solve(s, n) << "\n";
	}

	return 0;
}