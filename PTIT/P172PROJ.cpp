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

const int MAX = 1e7 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

bool mark[MAX];
vector<ll> primeList;
ll a, b, k;

void primeSieve(){
	memset(mark, true, sizeof(mark));
	mark[0] = mark[1] = 0;
	for (ll i = 2; i < MAX; i++)
		if (mark[i]){
			primeList.pb(i);
			for (ll j = i*i; j < MAX; j += i)
				mark[j] = false;
		}
}

int isPrime(ll n){
	if (n < MAX)
		return mark[n];
	for (int i = 0; primeList[i]*primeList[i] <= n; i++)
		if (n % primeList[i] == 0)
			return 0;
	return 1;
}

ll calcSmall(){
	int n = 0;
	while (primeList[n] < k) n++;
	int m = 1<<n;
	ll res = 0;

	--a;
	for (int i = 0; i < m; i++){
		ll div = k;
		int cnt = 0;
		REP(j,0,n)
			if ((i >> j) & 1){
				cnt++;
				div *= primeList[j];
			}
		if (cnt & 1)
			res -= b/div - a/div;
		else
			res += b/div - a/div;
	}
	return res;
}

ll Try(ll val, int pos){
	ll res = (a <= val && val <= b);
	for (int i = pos; val*primeList[pos] <= b; pos++)
		res += Try(val*primeList[pos], pos);
	return res;
}

ll calcLarge(){
	int i = 0;
	while (primeList[i] != k)
		i++;
	return Try(k, i);
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	primeSieve();

	cin >> a >> b >> k;

	if (!isPrime(k)){
		cout << 0;
		return 0;
	}
	if (k*k > b){
		cout << (a <= k && k <= b);
		return 0;
	}
	if (k < 72)
		cout << calcSmall();
	else
		cout << calcLarge();

	return 0;
}