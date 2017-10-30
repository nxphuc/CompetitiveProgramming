#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	string s;

	cin >> s;
	cout << (s[1] == '+' ? s[0] + s[2] - 96 : s[0] - s[2]);

	return 0;
}