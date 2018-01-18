#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	long long a, b, x, y;

	cin >> b >> a;
	if ((a & 1) || (b & 1)) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	a /= 2;
	b /= 2;
	// cout << a << " " << b << "\n";
	x = a - b;
	y = 2*b - a;
	if (x < 0 || y < 0) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << x << " " << y;

	return 0;
}