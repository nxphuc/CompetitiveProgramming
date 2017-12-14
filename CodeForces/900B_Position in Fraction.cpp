#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int a, b, c;

	cin >> a >> b >> c;
	a %= b;
	for (int i = 1; i <= 2*b; i++){
		int tmp = a * 10 / b;
		a = (a * 10) % b;
		if (tmp == c) {
			cout << i;
			return 0;
		}
	}
	cout << -1;

	return 0;
}