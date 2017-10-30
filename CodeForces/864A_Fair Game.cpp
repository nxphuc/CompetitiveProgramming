#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n;
	int a[110] = {0};

	cin >> n;
	for (int x, i = 0; i < n; i++) {
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= 100; i++) {
		if (!a[i]) {
			continue;
		}
		for (int j = i + 1; j <= 100; j++) {
			if (a[i] == a[j]) {
				if (a[i] + a[j] == n) {
					cout << "YES\n";
					cout << i << " " << j;
				}
				else {
					cout << "NO";
				}
				return 0;
			}
		}
	}
	cout << "NO";

	return 0;
}