#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	string s;

	cin >> s;
	list<char> str;
	list<char>::iterator it = str.begin();
	for (const char& ch : s) {
		if (ch == 'L') {
			if (it != str.begin()) {
				it--;
			}
		}
		else {
			if (ch == 'R') {
				if (it != str.end()) {
					it++;
				}
			}
			else {
				str.insert(it, ch);
			}
		}
	}
	for (const auto& ch : str) {
		cout << ch;
	}

	return 0;
}