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

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<int> > pq;
	int n, k, t, res = 0, cur = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> t;
		if (t >= 0)
			cur++;
		else{
			k--;
			if (cur == i)
				res++;
			if (cur > 0 && cur != i){
				pq.push(cur);
				cur = 0;
				res += 2;
			}
		}
	}

	if (k < 0){
		cout << -1;
		return 0;
	}

	// nếu cuối mùa mà không phải âm thì phải đổi bánh
	if (cur > 0)
		res++;

	// mỗi phần tử trong heap mà mất thì giảm số lần đổi đi 2
	// riêng cur cuối, nếu mất thì giảm đi 1
	while (pq.size()){
		if (pq.top() > k)
			break;
		res -= 2;
		k -= pq.top();
		pq.pop();
	}
	if (k >= cur && cur > 0)
		res--;
	cout << res;

	return 0;
}