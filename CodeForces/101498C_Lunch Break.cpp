#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int a, b, c, t, mn;

	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		mn = min(a, min(b, c));
		if (mn == a){
			cout << "First\n";
		}
		else {
			if (mn == b) {
				cout << "Second\n";
			}
			else {
				cout << "Third\n";
			}
		}
	}
	return 0;
}