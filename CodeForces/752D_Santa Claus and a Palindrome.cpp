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

map< string, vector<int> > lst;
vector<string> v;
string s, t;
int n, k, a;

int isPalin(string s){
	int i = 0, j = n-1;
	while (i < j)
		if (s[i] != s[j])
			return 0;
		else
			i++, j--;
	return 1;
}

string rev(string s){
	string t = "";
	for (int i = n-1; i >= 0; i--)
		t += s[i];
	return t;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> k >> n;
	REP(i,0,k){
		cin >> s >> a;
		if (isPalin(s)){
			if (!lst.count(s))
				v.pb(s);
			lst[s].pb(a);
		}
		else
			if (lst.count(s))
				lst[s][0] = max(lst[s][0], a);
			else{
				lst[s].pb(a);
				v.pb(s);
			}
	}

	ll res = 0;
	ll tot = 0;
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++){
		if (lst.count(v[i]) == 0)
			continue;

		if (isPalin(v[i])){
			s = v[i];
			sort(lst[s].begin(), lst[s].end(), greater<int>());
			if (lst[s].size() > 1){
				if (lst[s][0] + lst[s][1] > 0){
					tot += lst[s][0] + lst[s][1];
					if (lst[s].size() > 2)
						lst[s].resize(3);
					else
						lst[s].resize(2);
				}
				else{
					if (lst[s][0] <= 0)
						lst.erase(s);
					else
						if (lst[s][1] < 0)
							lst[s].resize(1);
				}
			}
		}
		else{
			s = v[i];
			t = rev(s);
			if (lst.count(t)){
				if (s < t && lst[s][0] + lst[t][0] > 0)
					tot += lst[s][0] + lst[t][0];
				lst.erase(s);
				lst.erase(t);
			}
			else
				lst.erase(s);
		}
	}

	res = tot;
	for (int i = 0; i < v.size(); i++){
		s = v[i];
		if (!lst.count(s))
			continue;
		if (lst[s].size() == 2)
			res = max(res, tot - lst[s][1]);
		else
			if (lst[s].size() == 1)
				res = max(res, tot + lst[s][0]);
			else
				if (lst[s].size() == 3)
					res = max(res, tot + lst[s][2]);
	}

	cout << res;

	return 0;
}
