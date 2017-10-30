#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n;
	string s;
	ll fact[22];
	int cnt[30];

	fact[0] = 1;
	for (int i = 1; i < 22; i++) {
		fact[i] = fact[i-1]*i;
	}

	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		memset(cnt, 0, sizeof(cnt));
		for (char ch : s) {
			cnt[ch - 'a']++;
		}
		int num_odd = 0;
		for (int& x : cnt) {
			num_odd += x % 2;
			x /= 2;
		}
		if (num_odd > 1) {
			cout << 0 << "\n";
		}
		else {
			ll res = fact[n/2];
			for (int x : cnt) {
				res /= fact[x];
			}
			cout << res << "\n";
		}
	}

	return 0;
}