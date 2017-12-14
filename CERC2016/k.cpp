#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	string s;
	int n;
	vector<int> a, res;

	cin >> s;
	n = s.length();
	a.push_back(0);
	for (int i = 0; i < n; i++) {
		a.push_back(s[i] - '0');
	}
	for (int cnt, i = 1; i <= n; i += 3) {
		cnt = 0;
		for (int j = 0; j < 3; j++) {
			cnt += a[i + j] ^ a[i + j - 1];
		}
		if (cnt >= 2) {
			continue;
		}
		
		a[i] ^= 1;
		a[i + 1] ^= 1;
		cnt = 0;
		for (int j = 0; j < 3; j++) {
			cnt += a[i + j] ^ a[i + j - 1];
		}
		if (cnt >= 2) {
			res.push_back(i);
			continue;
		}
		a[i] ^= 1;
		a[i + 2] ^= 1;
		res.push_back(i + 1);
	}

	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}