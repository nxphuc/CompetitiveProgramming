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

const int MAX = 1e5 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

string s;
string a[MAX];
int n;
int good[30];

int match1(string s, string t){
	// cout << "# " << s << " " << t << "\n";
	if (s.length() != t.length())
		return 0;
	int n = s.length();
	for (int i = 0; i < n; i++)
		if (s[i] == '?'){
			if (!good[t[i] - 'a'])
				return 0;
		}
		else
			if (s[i] != t[i])
				return 0;
	return 1;
}

int isMatch(int id, int pos){
	if (pos == -1)
		return match1(s, a[id]);

	if (a[id].length() < pos)
		return 0;
	if (!match1(s.substr(0, pos), a[id].substr(0, pos)))
		return 0;
	int l = s.length() - pos - 1;
	int m = a[id].length() - l;
	if (l + pos > a[id].length())
		return 0;
	for (int i = pos; i < m; i++)
		if (good[a[id][i] - 'a']) return 0;
	string t = a[id].substr(m, l);
	return match1(s.substr(pos+1), t);
	return 0;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	cin >> s;
	for (char ch : s)
		good[ch - 'a'] = 1;
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int pos = s.find('*');
	for (int i = 0; i < n; i++)
		cout << (isMatch(i, pos) ? "YES\n" : "NO\n");

	return 0;
}