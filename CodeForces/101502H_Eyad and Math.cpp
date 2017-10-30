#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t;
	double a, b, c, d;

	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d;
		b *= log(a);
		d *= log(c);
		cout << (b > d ? ">\n" : "<\n");
	}

	return 0;
}