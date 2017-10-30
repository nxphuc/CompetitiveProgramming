#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int l, r;
	cin >> l >> r;
	if (l + r == 0) {
		cout << "Not a moose";
		return 0;
	}
	cout << (l == r ? "Even " : "Odd ") << 2*max(l, r);

	return 0;
}