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

int n;
ll pos1, pos2;
int a[MAX];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	cin >> n;
	REP(i,0,n) cin >> a[i];
	sort(a,a+n);
	while (pos1 < n && a[pos1] == a[0]) pos1++;
	if (pos1 > 2)
		cout << (pos1*(pos1-1)*(pos1-2)/6);
	else{
		pos2 = pos1;
		while (pos2 < n && a[pos2] == a[pos1]) pos2++;
		if (pos2 > 2){
			if (pos1 == 1){
				--pos2;
				cout << pos2*(pos2-1)/2;
			}
			else
				cout << pos1*(pos1-1)/2;
		}
		else{
			pos1 = pos2;
			while (pos1 < n && a[pos1] == a[pos2]) pos1++;
			cout << pos1 - pos2;
		}
	}

	return 0;
}