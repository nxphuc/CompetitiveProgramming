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

int type[6] = {4, 6, 8, 10, 12, 20};
int typeID[21];
double f[7][21][410];

void prepare(){
	REP(i,0,6){
		typeID[type[i]] = i;

		f[i][0][0] = 1;
		for (int j = 1; j <= 20; j++){
			for (int k = 1; k <= 400; k++)
				if (k < j || k > type[i]*j)
					f[i][j][k] = 0;
				else{
					f[i][j][k] = 0;
					for (int x = 1; x <= type[i]; x++)
						if (k - x >= 0)
							f[i][j][k] += f[i][j-1][k - x];
					f[i][j][k] /= type[i];
				}
		}

		for (int j = 1; j <= 20; j++)
			for (int k = 400; k > 0; k--)
				f[i][j][k] += f[i][j][k+1];
	}
}

void getInput(string s, int &x, int &y, int &z){
	x = 0;
	int i = 0;
	while (s[i] != 'd')
		x = x*10 + s[i++] - '0';
	
	i++;
	y = 0;
	while (i < s.length() && s[i] != '+' && s[i] != '-')
		y = y*10 + s[i++] - '0';

	z = 0;
	if (i < s.length()){
		int flag = s[i] == '+' ? 1 : -1;
		i++;
		while (i < s.length())
			z = z*10 + s[i++] - '0';
		z *= flag;
	}
}

double calcProbability(int h, int x, int y, int z){
	h -= z;
	if (h <= 1)
		return 1;
	if (h > 400)
		return 0;
	return f[typeID[y]][x][h];
}

int main(){
	// freopen("fighting_the_zombie.txt", "rt", stdin);
	// freopen("fighting_the_zombie.out", "wt", stdout);
	ios::sync_with_stdio(false);

	prepare();

	int t, h, n, x, y, z;
	double res;
	string s;

	cin >> t;
	FOR(cs,1,t){
		cin >> h >> n;
		res = 0;
		while (n--){
			cin >> s;
			getInput(s, x, y, z);
			res = max(res, calcProbability(h, x, y, z));
		}
		cout << "Case #" << cs << ": " << fixed << setprecision(6) << res << "\n";
	}

	return 0;
}