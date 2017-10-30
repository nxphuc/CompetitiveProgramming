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
const double eps = 1e-8;

double f[MAX];

int calc(int k, double p){
	int l = k, r = 1e6;
	int m;
	int res = 1e6;

	while (l <= r){
		m = (l + r)/2;
		double sum = 0;
		REP(i,1,k)
			sum += f[i]*pow(1.0*i/k, m);
		if (1.0 - sum >= (p - inf)/2000){
			res = m;
			r = m-1;
		}
		else
			l = m+1;
	}

	return res;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int k, q, p;

	f[0] = 1;
	cin >> k >> q;
	REP(i,1,k)
		f[i] = f[i-1]*(k-i+1)/i;
	while (q--){
		cin >> p;
		cout << calc(k, p) << "\n";
	}

	return 0;
}