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

const int MAX = 1e3 + 30;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, k, x, a;
int f[2][MAX];

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> k >> x;
	REP(i,0,n){
		cin >> a;
		f[0][a]++;
	}
	FOR(i,1,k){
		int cur = i & 1;
		int last = 1 - cur;
		n = 0;
		REP(j,0,1025)
			f[cur][j] = 0;
		REP(j,0,1025){
			if (f[last][j]){
				if (n & 1){
					f[cur][j ^ x] += f[last][j]/2;
					f[cur][j] += (f[last][j] + 1)/2;
				}
				else{
					f[cur][j ^ x] += (f[last][j] + 1)/2;
					f[cur][j] += f[last][j]/2;
				}
				n += f[last][j];
			}
		}
	}
	for (int i = 1024; ; i--)
		if (f[k & 1][i]){
			cout << i << " ";
			break;
		}
	for (int i = 0; ; i++)
		if (f[k & 1][i]){
			cout << i;
			break;
		}

	return 0;
}