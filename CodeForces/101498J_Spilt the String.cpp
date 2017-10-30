#include <bits/stdc++.h>
using namespace std;

vector<int> a;

void split(string& s) {
	stringstream ss(s);
	a.clear();
	while (ss >> s) {
		a.push_back(s.length());
	}
}

int canSplit(int l) {
	int cur = 0;
	for (const int& x : a) {
		cur += x + 1;
		if (cur > l) {
			return 0;
		}
		if (cur == l) {
			cur = 0;
		}
	}
	return !cur;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n, flag;
	string s;

	cin >> t;
	getline(cin, s);
	while (t--) {
		getline(cin, s);
		n = s.length() + 1;
		split(s);
		flag = 0;
		for (int i = 2; i*i <= n; i++) {
			if (n % i == 0 && (canSplit(i) || canSplit(n/i))) {
				flag = 1;
				break;
			}
		}
		cout << (flag ? "YES\n" : "NO\n");
	}

	return 0;
}