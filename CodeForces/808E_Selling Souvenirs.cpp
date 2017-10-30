// /*
// Author:
// Prob:
// Link:
// Tag:
// Comp:
// */

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define ull unsigned long long
// #define ii pair<int,int>
// #define iii pair<ii, int>

// #define fi first
// #define se second
// #define mp make_pair
// #define pb push_back
// #define ep emplace_back
// #define sz(a) (int) a.size()
// #define cl(a) a.clear()

// #define vi vector<int>
// #define vii vector<ii>

// #define FOR(x,a,b) for (int x=a;x<=b;x++)
// #define FOD(x,a,b) for (int x=a;x>=b;x--)
// #define REP(x,a,b) for (int x=a;x<b;x++)
// #define RED(x,a,b) for (int x=a;x>b;x--)

// const int MAX = 1e6 + 10;
// const int MAXN = 1e6 + 10;
// const int MOD = 1e9 + 7;
// const int inf = 1e9;
// const double pi = acos(-1.0);
// const double eps = 1e-6;

// priority_queue< int> maxHeap[3];
// priority_queue< int, vector<int>, greater<int> > minHeap[3];
// ll a[3];
// int n, m, c, w;
// ll s;

// int getValue(int id){
// 	if (maxHeap[id].empty())
// 		return -1;
// 	int res = maxHeap[id].top();
// 	if (id){
// 		if (minHeap[id-1].empty())
// 			return -1;
// 		res -= minHeap[id-1].top();
// 	}
// 	return res;
// }

// void updateHeap(int id){
// 	s += getValue(id);
// 	int val = maxHeap[id].top();
// 	maxHeap[id].pop();
// 	minHeap[id].push(val);
// 	if (id){
// 		val = minHeap[id-1].top();
// 		minHeap[id-1].pop();
// 		maxHeap[id-1].push(val);
// 	}
// }

// int main(){
// 	freopen("test.in", "rt", stdin);
// 	// freopen("test.ou", "wt", stdout);
// 	ios::sync_with_stdio(false);

// 	cin >> n >> w;
// 	REP(i,0,n){
// 		cin >> w >> c;
// 		maxHeap[w-1].push(c);
// 	}
// 	while(1){
// 		REP(i,0,3) a[i] = getValue(i);
// 		int mx = 0;
// 		REP(i,0,3)
// 			mx = a[i] > a[mx] ? i : mx;
// 		if (a[mx] == -1)
// 			break;
// 		updateHeap(mx);
// 	};
// 	cout << s << "\n";

// 	return 0;
// }