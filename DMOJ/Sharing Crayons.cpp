#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n, m, x;
	long long s = 0;
	unordered_map<int, int> cnt;
	long long res = 0;

	cin >> n >> m;
	assert(1 <= n && n <= 100000);
	assert(1 <= n && n <= 1000000000);
	cnt[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> x;
		assert(1 <= x && x <= 1000000000);
		s = (s + x % m + 1LL*m*m) % m;
		res += cnt[s];
		cnt[s]++;
	}
	// for (const auto& kvp : cnt) {
	// 	cout << kvp.first << " " << kvp.second << "\n";
	// }
	cout << res;

	return 0;
}