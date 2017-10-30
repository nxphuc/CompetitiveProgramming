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

int t, n, len, A, B;
int a[MAX];

ll calcDist(ll posStart){
	ll ret = 0;
	for (int i = 0; i < n; i++){
		ret += labs(posStart - a[i]);
		posStart += len;
	}
	return ret;
}

int findSnake(ll pos){
	for (int i = 0; i < n; i++)
		if (pos == a[i])
			return 1;
	return 0;
}

ll ternarySearch(){
	ll l = A, r = B - n*len;
	ll midLeft = (l + l + r)/3, midRight = (l + r + r)/3;
	ll distMidLeft, distMidRight;

	while (l != midLeft && midLeft != midRight && midRight != r){
		distMidLeft = calcDist(midLeft);
		distMidRight = calcDist(midRight);
		if (distMidLeft > distMidRight)
			l = midLeft;
		else
			r = midRight;
		midLeft = (l + l + r)/3;
		midRight = (l + r + r)/3;
	}
	ll res = calcDist(l);
	for (int i = l; i <= r; i++)
		res = min(res, calcDist(i));
	// for (int i = l; i <= r; i++)
	// 	if (res == calcDist(i))
	// 		assert(findSnake(i));
	return res;
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> len >> A >> B;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a,a+n);
		cout << ternarySearch() << "\n";
	}

	return 0;
}