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

int n, m, x;
int a[MAX][MAX][2];
int f[MAX][MAX][2];
int posZero = -1;

void dp(int type){
	FOR(i,1,n)
		FOR(j,1,m)
			if (i == 1)
				if (j == 1)
					f[i][j][type] = a[i][j][type];
				else
					f[i][j][type] = f[i][j-1][type] + a[i][j][type];
			else
				if (j == 1)
					f[i][j][type] = f[i-1][j][type] + a[i][j][type];
				else
					f[i][j][type] = min(f[i-1][j][type], f[i][j-1][type]) + a[i][j][type];
}

void trace(int type){
	string s = "";
	while (n != 1 || m != 1){
		if (n == 1){
			s += "R";
			m--;
		}
		else
			if (m == 1){
				s += "D";
				n--;
			}
			else{
				if (f[n-1][m][type] + a[n][m][type] == f[n][m][type]){
					s += "D";
					n--;
				}
				else{
					s += "R";
					m--;
				}
			}
	}
	for (int i = s.length()-1; i >= 0; i--)
		cout << s[i];
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	m = n;
	FOR(i,1,n){
		FOR(j,1,m){
			cin >> x;
			if (!x)
				posZero = (i-1)*m + j - 1;
			else{
				while (x % 2 == 0){
					a[i][j][0]++;
					x /= 2;
				}
				while (x % 5 == 0){
					a[i][j][1]++;
					x /= 5;
				}
			}
		}
	}
	dp(0);
	dp(1);
	if (posZero != -1 && f[n][m][0] && f[n][m][1]){
		cout << 1 << "\n";
		int x = posZero/m + 1;
		int y = posZero%m + 1;
		FOR(i,2,x)
			cout << "D";
		FOR(i,2,m)
			cout << "R";
		FOR(i,x+1,n)
			cout << "D";
	}
	else{
		cout << min(f[n][m][0], f[n][m][1]) << "\n";
		if (f[n][m][0] < f[n][m][1])
			trace(0);
		else
			trace(1);
	}

	return 0;
}