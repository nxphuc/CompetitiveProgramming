#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n, k;

	cin >> t;
	while (t--) {
		cin >> n >> k;
		switch (k) {
			case 1:
				cout << n << " ";
				for (int i = 0; i < n; i++) {
					cout << "a";
				}
				break;
			case 2:
				switch (n) {
					case 1:
						cout << "1 a";
						break;
					case 2:
						cout << "1 ab";
						break;
					case 3:
						cout << "2 aab";
						break;
					case 4:
						cout << "2 aabb";
						break;
					case 5:
						cout << "3 aaaba";
						break;
					case 6:
						cout << "3 aaabab";
						break;
					case 7:
						cout << "3 aaababb";
						break;
					case 8:
						cout << "3 aaababbb";
						break;
					default:
						cout << "4 aaaa";
						string tmp = "babbaa";
						for (int i = 4; i < n; i++) {
							cout << tmp[(i - 4) % 6];
						}
						break;
				}
				break;
			default:
				cout << "1 ";
				for (int i = 0; i < n; i++) {
					cout << char('a' + i % 3);
				}
		}
		cout << "\n";
	}

	return 0;
}