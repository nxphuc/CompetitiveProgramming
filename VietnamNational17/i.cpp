#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;

vector<int> a[MAX];
int vis[MAX];

string intToString(int n) {
	string s = "";
	while (n) {
		s = char(n % 10 + '0') + s;
		n /= 10;
	}
	return s;
}

int stringToInt(const string& s) {
	int n = 0;
	for (char ch : s) {
		n = n * 10 + ch - '0';
	}
	return n;
}

void rotate(int n) {
	if (vis[n]) {
		return;
	}
	vis[n] = 1;
	string s = intToString(n);
	string t = s;
	int l = s.length();
	// cout << s << " " << l << "\n";
	for (int i = 1; i < l; i++) {
		t = t[l-1] + t.substr(0, l-1);
		// cout << "# " << t << "\n";
		if (t[0] != '0' && t > s) {
			a[n].push_back(stringToInt(t));
		}
	}
	sort(a[n].begin(), a[n].end());
	a[n].resize(unique(a[n].begin(), a[n].end()) - a[n].begin());
}

int main() {
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	// for (int i = 12; i <= 22; i++) {
	// for (int i = 1; i < MAX; i++) {
	// 	rotate(i);
	// }

	int cs, l, r;
	cin >> cs;
	while (cs--) {
		cin >> l >> r;
		long long res = 0;
		for (int i = l; i <= r; i++) {
			rotate(i);
			for (int x : a[i]) {
				res += x > i && x <= r;
			}
		}
		cout << res << "\n";
	}

	return 0;
}