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

int cnt[5];
int t, n, p, x;

int solve2(){
	return cnt[0] + (cnt[1] + 1)/2;
}

int solve3(){
	int res = cnt[0];
	int tmp = min(cnt[1], cnt[2]);

	cnt[1] -= tmp;
	cnt[2] -= tmp;
	res += tmp;
	res += cnt[1] / 3 + cnt[2] / 3;
	res += cnt[1] % 3 || cnt[2] % 3;
	return res;
}

int solve4(){
	int res = cnt[0] + cnt[2]/2;
	int tmp = min(cnt[1], cnt[3]);

	cnt[2] &= 1;
	cnt[1] -= tmp;
	cnt[3] -= tmp;
	res += tmp;
	if (cnt[2]){
		if (cnt[1] >= 2){
			res++;
			cnt[1] -= 2;
			cnt[2] = 0;
		}
		else
			if (cnt[3] >= 2){
				res++;
				cnt[3] -= 2;
				cnt[2] = 0;
			}
	}
	res += cnt[1]/4 + cnt[3]/4;
	res += cnt[1] % 4 || cnt[3] % 4 || cnt[2];
	return res;
}

int main(){
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> t;
	FOR(cs,1,t){
		cin >> n >> p;
		REP(i,0,p) cnt[i] = 0;
		REP(i,0,n){
			cin >> x;
			cnt[x % p]++;
		}

		cout << "Case #" << cs << ": ";
		switch(p){
			case 2:
				cout << solve2() << "\n";
				break;
			case 3:
				cout << solve3() << "\n";
				break;
			case 4:
				cout << solve4() << "\n";
				break;
		}
	}

	return 0;
}