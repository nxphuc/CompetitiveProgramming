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

ll f[MAX];
int a[MAX];
int cnt[MAX];
int n, k, numDiff;

void increase(int x){
	if (x > k)
		return;
	if (!cnt[x])
		numDiff++;
	cnt[x]++;
}

void decrease(int x){
	if (x > k)
		return;
	cnt[x]--;
	if (!cnt[x])
		numDiff--;
}

ll Pow(ll b, ll p){
	if (!p)
		return 1;
	if (p == 1)
		return b % MOD;
	ll ret = Pow(b, p/2);
	ret = (ret * ret) % MOD;
	if (p & 1)
		ret = (ret * b) % MOD;
	return ret;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	cin >> n >> k;
	if (k >= n)
		cout << Pow(2, n-1) << "\n";
	else{
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int l = 1, r = 1;
		for (; r <= n; r++){
			increase(a[r]);
			while (numDiff > k)
				decrease(a[l++]);
			f[r] = r - l + 1;
		}
		l = 0;
		f[0] = 1;
		ll sum = 0;
		for (int i = 1; i <= n; i++){
			sum = (sum + f[i-1]) % MOD;
			while (l + f[i] < i)
				sum = (sum - f[l++] + MOD) % MOD;
			f[i] = sum;
		}
		cout << f[n] << "\n";
	}

	return 0;
}