#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int x = 1, y = 2;
	int w;
	while (n--) {
		cin >> w;
		if (w == x) {
			y = 6 - x - y;
		}
		else {
			if (w == y) {
				x = 6 - x - y;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";

	return 0;
}