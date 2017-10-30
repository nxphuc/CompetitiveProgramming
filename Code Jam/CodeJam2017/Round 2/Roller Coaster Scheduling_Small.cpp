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

const int MAX = 1e3 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int a[3][MAX];
int t, n, m, c, b, p;

int calcY(int& resX){
	int flag = 0;
	FOR(i,1,n)
		if (a[1][i] && a[2][i]){
			flag = i;
			break;
		}
	if (flag)
		if (flag > 1){
			resX += max(a[1][flag], a[2][flag]);
			return min(a[1][flag], a[2][flag]);
		}
		else{
			resX += a[1][flag] + a[2][flag];
			return a[1][flag] + a[2][flag];
		}
	FOR(i,1,n)
		resX += a[1][i] + a[2][i];
	return 0;
}

int main(){
	freopen("B-small-attempt1.in", "rt", stdin);
	freopen("B-small-attempt1.ou", "wt", stdout);
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	FOR(cs,1,t){
		memset(a,0,sizeof(a));
		cin >> n >> c >> m;
		while (m--){
			cin >> p >> b;
			a[b][p]++;
		}
		int resX = 0;
		for (int i = 1, j = 1; i <= n; ){
			while (j <= n && (j <= i || !a[2][j])) j++;
			if (j > n)
				break;
			int tmp = min(a[1][i], a[2][j]);
			a[1][i] -= tmp;
			a[2][j] -= tmp;
			resX += tmp;
			if (!a[1][i]) i++;
		}

		for (int i = 1, j = 1; i <= n; ){
			while (j <= n && (j <= i || !a[1][j])) j++;
			if (j > n)
				break;
			int tmp = min(a[2][i], a[1][j]);
			a[2][i] -= tmp;
			a[1][j] -= tmp;
			resX += tmp;
			if (!a[2][i]) i++;
		}

		int resY = calcY(resX);
		cout << "Case #" << cs << ": " << resX << " " << resY << "\n";
	}

	return 0;
}