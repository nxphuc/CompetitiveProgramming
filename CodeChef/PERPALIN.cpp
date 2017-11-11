#include <bits/stdc++.h>
using namespace std;
 
int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);
 
	int t, n, p;
	string s;
 
	cin >> t;
	while (t--) {
		cin >> n >> p;
		if (n % p || p < 3) {
			cout << "impossible\n";
		}
		else {
			s.assign(p, 'a');
			if (p & 1) {
				s[p / 2] = 'b';
			}
			else {
				s[p/2] = s[p/2-1] = 'b';
			}
			n /= p;
			while (n--) {
				cout << s;
			}
			cout << "\n";
		}
	}
 
	return 0;
} 