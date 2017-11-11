#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);
 
	int t, n, prv;
	int cnt[2];
	string s;
 
	cin >> t;
	while (t--) {
		cin >> s;
		prv = -1, cnt[0] = cnt[1] = 0;
		n = s.length();
		for (int i = 0; i < n; i++) {
			if (s[i] != '.') {
				cnt[s[i] - 'A']++;
				if (prv != -1 && s[prv] == s[i]) {
					cnt[s[i] - 'A'] += i - prv - 1;
				}
				prv = i;
			}
		}
		cout << cnt[0] << " " << cnt[1] << "\n";
	}
 
	return 0;
} 