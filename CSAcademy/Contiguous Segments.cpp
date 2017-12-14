#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<pair<int,int>> a;
	
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < n; i++) {
		assert(a[i].first <= a[i].second);
		assert(a[i].first >= a[i-1].second);
	}
	// for (auto kvp : a) {
	//     cout << kvp.first << " " << kvp.second << "\n";
	// }
	long long res = 0;
	int prv = a[n/2].first;
	// cout << prv << "\n";
	for (int i = n/2-1; i >= 0; i--) {
		res += prv - a[i].second;
		prv -= a[i].second - a[i].first;
		// cout << "# " << res << "\n";
	}
	prv = a[n/2].second;
	// cout << prv << "\n";
	for (int i = n/2 + 1; i < n; i++) {
		res += a[i].first - prv;
		prv += a[i].second - a[i].first;
		// cout << "@ " << res << "\n";
	}
	cout << res;
	return 0;
}