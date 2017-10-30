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
const double eps = 1e-6;

int n;
int a[MAX], s[MAX];

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	FOR(i,1,n){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}

	if (s[n]){
		cout << "YES\n";
		cout << 1 << "\n";
		cout << 1 << " " << n << "\n";
	}
	else{
		for (int i = 1; i < n; i++)
			if (s[i]){
				cout << "YES\n";
				cout << 2 << "\n";
				cout << 1 << " " << i << "\n";
				cout << i+1 << " " << n;
				return 0;
			}
		cout << "NO";
	}

	return 0;
}