#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int INF = 1e9;

string toString(ll num) {
	stringstream ss;
	ss << num;
	return ss.str();
}

int isValid(string s, string t) {
	ll tot = 0;
	for (char ch : s) {
		tot += ch - '0';
	}
	return toString(tot) == t;
}

int main() {
	freopen("PASSWORD.INP", "rt", stdin);
	freopen("PASSWORD.OUT", "wt", stdout);
	ios::sync_with_stdio(false);

	string s, t;

	cin >> s >> t;

	assert(s.length() >= t.length());
	if (s == t) {
		cout << "1 1";
		return 0;
	}
	int l = 0, rt = t.length() - 1, rs = s.length() - 1;
	while (rt > 0 && rs > 0 && s[rs] == t[rt]) {
		rt--;
		rs--;
	}
	while (l <= rs && l <= rt && s[l] == t[l]) {
		l++;
	}
	pair<int,int> res = make_pair(INF, INF);
	for (int i = 0; i <= 10; i++) {
		if (l - i < 0) {
			break;
		}
		for (int j = 0; j <= 10; j++) {
			if (rt + j >= t.length() || rs + j >= s.length()) {
				break;
			}
			if (isValid(s.substr(l - i, rs + j - (l - i) + 1), t.substr(l - i, rt + j - (l - i) + 1))) {
				res = min(res, make_pair(l - i + 1, rs + j + 1));
			}
		}
	}
	cout << res.first << " " << res.second;
	// cout << l << " " << rs << " " << rt << "\n";

	return 0;
}