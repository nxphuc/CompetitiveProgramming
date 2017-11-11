#include <bits/stdc++.h>
using namespace std;
 
const int INF = 2e9;
const int MAX = 1e6 + 10;
 
int t, n, x;
int a[MAX];
 
int solve() {
	int lft = -INF, rht = INF;
	for (int i = 0; i < n-1; i++) {
		if (a[i] < lft || rht < a[i]) {
			return 0;
		}
		if (a[i] > a[i+1]) {
			rht = a[i];
		}
		else {
			lft = a[i];
		}
	}
	return lft <= a[n-1] && a[n-1] <= rht;
}
 
int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);
 
	cin >> t;
	while (t--) {
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << (solve() ? "YES\n" : "NO\n");
	}
 
	return 0;
} 