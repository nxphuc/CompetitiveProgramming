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

int t, n, k;
string s;

int isValid(){
	int cnt[2][2] = {0};
	REP(i,0,n)
		cnt[i & 1][s[i] - '0']++;
	return min(cnt[1][1] + cnt[0][0], cnt[0][1] + cnt[1][0]) <= k;
}

int isValid(int val){
	if (val == 1)
		return isValid();
	int cnt = 0;
	int cur = 1;
	REP(i,1,n)
		if (s[i] == s[i-1])
			cur++;
		else{
			cnt += cur / (val + 1);
			cur = 1; 
		}
	return (cnt + cur / (val + 1)) <= k;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> k >> s;
		int l = 1, r = n;
		int m, res;

		while (l <= r){
			m = (l + r)/2;
			if (isValid(m)){
				res = m;
				r = m-1;
			}
			else
				l = m+1;
		}
		cout << res << "\n";
	}

	return 0;
}