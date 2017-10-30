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

const int MAX = 1510;
const int MAXN = 1e6 + 10;
const ll MOD = 307445734561781LL;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, k;
string s, b;
ll a[MAX][MAX];
int sz[MAX];

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	memset(a,0,sizeof(a));
	memset(sz,0,sizeof(sz));

	cin >> s;
	cin >> b;
	cin >> k;
	
	assert(0 < s.size() && s.size() <= 1500);
	assert(b.size() == 26);
	assert(0 <= k && k <= s.size());
	REP(i,0,s.size()) assert('a' <= s[i] && s[i] <= 'z');

	n = s.length();
	s = "#" + s;
	FOR(i,1,n){
		int cnt = 0;
		ll hash = 0;
		FOR(j,i,n){
			hash = (hash*26 + s[j] - 'a') % MOD;
			cnt += b[s[j] - 'a'] == '0';
			if (cnt > k) break;
			a[j-i+1][sz[j-i+1]] = hash;
			sz[j-i+1]++;
		}
	}
	FOR(i,1,n)
		sort(a[i], a[i] + sz[i]);

	int res = 0;
	FOR(i,1,n){
		res += sz[i] > 0;
		REP(j,1,sz[i])
			res += a[i][j] != a[i][j-1];
	}
	cout << res;

	return 0;
}