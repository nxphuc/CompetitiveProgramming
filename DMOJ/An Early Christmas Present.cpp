#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, a, mn = INT_MAX;
	cin >> n;
	while (n--) {
		cin >> a;
		mn = min(mn, a);
	}
	cout << mn;

	return 0;
}