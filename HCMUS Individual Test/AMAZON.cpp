#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int a[MAX];
int n, res;

int main() {
	freopen("AMAZON.INP", "rt", stdin);
	freopen("AMAZON.OUT", "wt", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	res = n;
	int m = unique(a, a + n) - a;
	for (int i = 0; i < m; i++) {
		int pos = lower_bound(a+i, a+m, a[i] + n) - (a + i);
		res = min(res, n - pos);
	}
	for (int i = 0; i < m; i++) {
		int pos = (a + i) - upper_bound(a, a+i, a[i] - n);
		res = min(res, n - pos);
	}
	cout << res;

	return 0;
}