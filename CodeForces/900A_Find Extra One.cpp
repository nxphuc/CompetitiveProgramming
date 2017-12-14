#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n;
	int cnt[2] = {0};

	cin >> n;
	for (int x, y, i = 0; i < n; i++) {
		cin >> x >> y;
		cnt[x > 0]++;
	}
	if (cnt[0] > 1 && cnt[0] < n-1) {
		cout << "No";
		return 0;
	}
	if (cnt[1] > 1 && cnt[1] < n-1) {
		cout << "No";
		return 0;
	}
	cout << "Yes";

	return 0;
}