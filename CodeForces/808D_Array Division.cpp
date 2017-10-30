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
int a[MAX];
ll s, t;
set<ll> st;

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> n;
	REP(i,0,n){
		cin >> a[i];
		s += a[i];
	}
	if (s & 1){
		cout << "NO";
		return 0;
	}
	s >>= 1;
	t = 0;
	REP(i,0,n){
		t += a[i];
		if (t == s){
			cout << "YES";
			return 0;
		}
	}
	t = 0;
	st.clear();
	REP(i,0,n){
		t += a[i];
		st.insert(a[i]);
		if (t > s && st.find(t - s) != st.end()){
			cout << "YES";
			return 0;
		}
	}

	t = 0;
	st.clear();
	FOD(i,n-1,0){
		t += a[i];
		st.insert(a[i]);
		if (t > s && st.find(t - s) != st.end()){
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}