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

string s[4];

int isWin(int x, int y){
	//row
	int minY = y, maxY = y;
	while (minY >= 0 && s[x][minY] == s[x][y]) minY--;
	while (maxY < 4 && s[x][maxY] == s[x][y]) maxY++;
	if (maxY - minY == 4)
		return 1;

	int minX = x, maxX = x;
	while (minX >= 0 && s[minX][y] == s[x][y]) minX--;
	while (maxX < 4 && s[maxX][y] == s[x][y]) maxX++;
	if (maxX - minX == 4)
		return 1;

	minX = maxX = x;
	minY = maxY = y;
	while (minX >= 0 && minY >= 0 && s[minX][minY] == s[x][y])
		minX--, minY--;
	while (maxX < 4 && maxY < 4 && s[maxX][maxY] == s[x][y])
		maxX++, maxY++;
	if (maxX - minX == 4)
		return 1;

	minX = maxX = x;
	minY = maxY = y;
	while (minX >= 0 && maxY < 4 && s[minX][maxY] == s[x][y])
		minX--, maxY++;
	while (maxX < 4 && minX >= 0 && s[maxX][minY] == s[x][y])
		maxX++, minY--;
	if (maxX - minX == 4)
		return 1;
	return 0;
}

string check(char ch){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (s[i][j] == '.'){
				s[i][j] = ch;
				if (isWin(i, j))
					return "YES";
				s[i][j] = '.';
			}
	return "NO";
}

int main(){
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int cntX = 0;
	int cntO = 0;

	REP(i,0,4){
		cin >> s[i];
		REP(j,0,4){
			if (s[i][j] == 'x')
				cntX++;
			if (s[i][j] == 'o')
				cntO++;
		}
	}

	cout << check(cntX == cntO ? 'x' : 'o');

	return 0;
}