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

bool f[MAX];

void primeSieve(){
	memset(f, 1, sizeof(f));

	f[0] = f[1] = 0;
	for (ll i = 2; i*i < MAX; i++)
		if (f[i])
			for (ll j = i*i; j < MAX; j += i)
				f[j] = 0;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	primeSieve();

	int n;
	cin >> n;
	if (n < 3)
		cout << "1\n";
	else
		cout << "2\n";
	FOR(i,2,n+1)
		cout << (f[i] ? "1 " : "2 ");

	return 0;
}