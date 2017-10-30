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

const int MAX = 30;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

string s[MAX];
int R, C;

int goUp(int r, int c){
	return r > 0 && string("+|14").find(s[r-1][c]) != string::npos;
}

int goDown(int r, int c){
	return r < R && string("+|23").find(s[r+1][c]) != string::npos;
}

int goLeft(int r, int c){
	return c > 0 && string("+-12").find(s[r][c-1]) != string::npos;
}

int goRight(int r, int c){
	return c < C-1 && string("+-34").find(s[r][c+1]) != string::npos;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	REP(i,0,R) cin >> s[i];
	// REP(i,0,R){
	// 	// REP(j,0,C)
	// 		cout << s[i] << "\n";
	// }
	REP(i,0,R)
		REP(j,0,C){
			if (s[i][j] != '.')
				continue;
			int tmp = goUp(i, j) + (goDown(i, j) << 1) + (goLeft(i, j) << 2) + (goRight(i, j) << 3);
			// cout << tmp << " ";
			switch (tmp){
				case 15:
					cout << i+1 << " " << j+1 << " +";
					return 0;
				case 3:
					cout << i+1 << " " << j+1 << " |";
					return 0;
				case 12:
					cout << i+1 << " " << j+1 << " -";
					return 0;
				case 10:
					cout << i+1 << " " << j+1 << " 1";
					return 0;
				case 9:
					cout << i+1 << " " << j+1 << " 2";
					return 0;
				case 5:
					cout << i+1 << " " << j+1 << " 3";
					return 0;
				case 6:
					cout << i+1 << " " << j+1 << " 4";
					return 0;
			}
		}

	return 0;
}