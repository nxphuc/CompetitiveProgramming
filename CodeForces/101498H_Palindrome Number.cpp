#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n, k, l, r, tmp;
	string str;

	cin >> t;
	while (t--){
		cin >> n >> k;
		if (k > 9*n || (k % 2 == 1 && n % 2 == 0)) {
			cout << -1 << "\n";
			continue;
		}
		str.assign(n, '0');
		l = 0, r = n-1;
		while (k > 0 && l < r) {
			tmp = min(9, k/2);
			str[l] = str[r] = str[l] + tmp;
			k -= 2*tmp;
			l++, r--;
		}
		if (n % 2 == 1 && k > 0) {
			tmp = min('9' - str[n/2], k);
			k -= tmp;
			str[n/2] += tmp;
		}
		if (k != 0 || str[0] == '0') {
			cout << -1 << "\n";
		}
		else {
			cout << str << "\n";
		}
	}
	return 0;
}