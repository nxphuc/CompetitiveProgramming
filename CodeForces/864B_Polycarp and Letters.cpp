#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, res = 0;
	string s;
	set<int> pos;

	cin >> n;
	cin >> s;
	for (auto& ch: s) {
		if (ch >= 'A' && ch <= 'Z') {
			res = max(res, (int)pos.size());
			pos.clear();
		}
		else {
			pos.insert(ch);
		}
	}
	cout << max(res, (int)pos.size());

	return 0;
}