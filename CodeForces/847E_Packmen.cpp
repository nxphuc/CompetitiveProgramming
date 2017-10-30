#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> asts, pacs;

int canFinish(int m) {
	int lo, hi, cur = 0;
	for (int& pos : pacs) {
		lo = hi = pos;
		while (cur < asts.size()) {
			lo = min(lo, asts[cur]);
			hi = max(hi, asts[cur]);
			if (min(hi + pos - 2*lo, 2*hi - pos - lo) <= m) {
				cur++;
			}
			else {
				break;
			}
		}
	}
	return cur == asts.size();
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			asts.push_back(i);
		}
		if (s[i] == 'P') {
			pacs.push_back(i);
		}
	}
	int lo = 0, hi = 2*n;
	int mi, res;
	while (lo <= hi) {
		mi = (lo + hi) >> 1;
		// cerr << lo << " " << hi << " " << mi << "\n";
		if (canFinish(mi)) {
			res = mi;
			hi = mi - 1;
		}
		else {
			lo = mi + 1;
		}
	}
	cout << res;

	return 0;
}