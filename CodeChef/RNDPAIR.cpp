#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		map<int, int> cnt;
		vector<int> a;

		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				cnt[a[i] + a[j]]++;
			}
		}
		cout << fixed << setprecision(8) << 1.0*cnt.rbegin()->second/(n*(n-1)/2) << "\n";
	}

	return 0;
}