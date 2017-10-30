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

int t, n, k, m, x;
vi a[MAX];
int cnt[MAX];

int canRemove(int id){
	REP(i,0,a[id].size())
		if (cnt[a[id][i]] < 2)
			return 0;
	return 1;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> k;

		memset(cnt,0,sizeof(cnt));
		REP(i,0,n){
			a[i].clear();
			cin >> m;
			while (m--){
				cin >> x;
				a[i].pb(x);
				cnt[x]++;
			}
		}

		int flag = 0;
		FOR(i,1,k)
			if (!cnt[i]){
				flag = -1;
				break;
			}
		if (!flag)
			REP(i,0,n)
				if (canRemove(i)){
					flag = 1;
					break;
				}
		cout << (flag ? (flag == -1 ? "sad\n" : "some\n") : "all\n");
	}

	return 0;
}