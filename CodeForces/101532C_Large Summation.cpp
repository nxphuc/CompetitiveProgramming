#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;

int a[MAX], b[MAX];
int n;

int find(int val) {
	int x = MOD - val - 1;
	int p = (upper_bound(b, b+n, x) - b - 1 + n) % n;
	if (b[p] != val) {
		return (val + b[p]) % MOD;
	}
	return (val + b[(p - 1 + n) % n]) % MOD;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t;

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b+n);
		for (int p1, p2, i = 0; i < n; i++) {
			cout << find(a[i]) << " ";
		}
		cout << "\n";
	}

	return 0;
}