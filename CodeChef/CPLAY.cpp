#include <bits/stdc++.h>
using namespace std;

string process(string g) {
	int w[2] = {0, 0};
	string s = "TEAM-";
	for (int i = 0; i < 10; i++) {
		w[i & 1] += g[i] == '1';
		if (w[i & 1] > w[1 - (i & 1)] + (10 - i) / 2) {
			s += char('A' + (i & 1));
			s += " ";
			return s + to_string(i+1);
		}
		if (w[i & 1] + (9 - i) / 2 < w[1 - (i & 1)]) {
			s += char('B' - (i & 1));
			s += " ";
			return s + to_string(i+1);
		}
	}
	for (int i = 10; i < 20; i += 2) {
		w[0] += g[i] == '1';
		w[1] += g[i + 1] == '1';
		if (w[0] != w[1]) {
			s += char(w[0] > w[1] ? 'A' : 'B');
			s += " ";
			return s + to_string(i+2);
		}
	}
	return "TIE";
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	string g;

	while (cin >> g) {
		cout << process(g) << "\n";
	}

	return 0;
}