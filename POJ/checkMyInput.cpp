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
	#ifndef ONLINE_JUDGE
		// freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	FILE* f1 = fopen("testCin.ou", "rt");
	FILE* f2 = fopen("testScanf.ou", "rt");
	int x, y, u, v;
	for (int i = 0; i < 100000; i++){
		fscanf(f1, "%d %d", &x, &y);
		fscanf(f2, "%d %d", &u, &v);
		if (x != u || v != y){
			printf("Wrong at %d\n", i+1);
			printf("Cin: %d %d", x, y);
			printf("Scanf: %d %d", u, v);
			return 0;
		}
	}

	return 0;
}