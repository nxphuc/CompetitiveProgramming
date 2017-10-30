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

inline ii sub(ii a, ii b){ return make_pair(a.fi - b.fi, a.se - b.se); }

inline int mul(ii a, ii b){ return a.fi*b.fi + a.se*b.se; }

inline int norm(ii a){ return a.fi*a.fi + a.se*a.se; }

double angle(ii a, ii o, ii b){
	a = sub(a, o);
	b = sub(b, o);
	return acos(1.0*mul(a, b) / sqrt(norm(a) * norm(b)));
}

int inCircle(ii p){
	p = sub(p, make_pair(50, 50));
	return norm(p) <= 2500;
}

string process(int percent, ii point){
	double a = angle(make_pair(50, 100), make_pair(50, 50), point);
	if (point.fi < 50)
		a = 2.0*pi - a;
	// cout << a*180/pi << "\n";
	if (a <= pi*2.0/100.0*percent && inCircle(point))
		return "black";
	return "white";
}

int main(){
	// freopen("progress_pie.txt", "rt", stdin);
	// freopen("progress_pie.out", "wt", stdout);
	ios::sync_with_stdio(false);

	int t, p, x, y;

	cin >> t;
	FOR(cs,1,t){
		cin >> p >> x >> y;
		cout << "Case #" << cs << ": " << process(p, make_pair(x, y)) << "\n";
	}

	return 0;
}