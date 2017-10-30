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

int mask[MAX];
vi prime;

void sieve(){
	for (ll i = 2; i < MAX; i++)
		if (!mask[i]){
			prime.pb(i);
			for (ll j = 1LL*i*i; j < MAX; j += i)
				mask[j] = 1;
		}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	sieve();
	int n;

	while (cin >> n, n){
		int i = 0, j = -1;
		int cnt = 0, s = 0;
		while (prime[i] <= n){
			if (j < i) j = i, s = 0;
			while (s < n)
				s += prime[j++];
			// cout << prime[i] << " " << prime[j-1] << " " << s << "\n";
			cnt += s == n;
			s -= prime[i++];
		}
		cout << cnt << "\n";
	}
	// cout << "\n";

	return 0;
}