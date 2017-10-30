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

const int MAX = 1e5 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int primes[MAX];

void prepare(){
	for (int i = 2; i < MAX; i++)
		primes[i] = 1;
	for (int i = 2; i < MAX; i++)
		if (primes[i])
			for (ll j = 1LL*i*i; j < MAX; j += i)
				primes[j] = 0;
	REP(i,1,MAX)
		primes[i] += primes[i-1];
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int g, n;

	prepare();
	cin >> g;
	while (g--){
		cin >> n;
		cout << (primes[n] & 1 ? "Alice" : "Bob") << "\n";
	}

	return 0;
}