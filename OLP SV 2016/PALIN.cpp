#include <bits/stdc++.h>
using namespace std;

void prepare(const string& s, string& t) {
	t = '$';
	for (const char& ch : s) {
		t += '#';
		t += ch;
	}
	t += "#@";
}

pair<int,int> manacher(const string& s) {
	pair<int,int> res = make_pair(0, 0);
	int center = 0, right = 0;
	vector<int> p(s.length(), 0);
	for (int i = 1; i < s.length() - 1; i++) {
		int mirror = 2*center - i;
		if (right > i) {
			p[i] = min(right - i, p[mirror]);
		}

		while (s[i + 1 + p[i]] == s[i - 1 - p[i]]) {
			p[i]++;
		}

		if (p[i] & 1) {
			res.second = max(res.second, p[i]);
		}
		else {
			res.first = max(res.first, p[i]);
		}
		if (i + p[i] > right) {
			center = i;
			right = i + p[i];
		}
	}
	return res;
}

int main() {
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	string s, t;
	cin >> s;
	prepare(s, t);
	pair<int, int> res = manacher(t);
	int q, l;
	cin >> q;
	while (q--) {
		cin >> l;
		if (l & 1) {
			cout << (l <= res.second ? 1 : 0) << "\n";
		}
		else {
			cout << (l <= res.first ? 1 : 0) << "\n";
		}
	}

	return 0;
}