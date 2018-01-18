#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

int f[200][20][10][10];

int exists(int remain, int id, int lower, int upper, string s, string t) {
	if (f[remain][id][lower][upper] != -1) {
		return f[remain][id][lower][upper];
	}
	if (id == s.length()) {
		return f[remain][id][lower][upper] = remain == 0;
	}
	int l = 0, r = 9;
	if (lower) {
		l = s[id] - '0';
	}
	if (upper) {
		r = t[id] - '0';
	}
	for (int i = l; i <= r; i++) {
		if (remain >= i && exists(remain - i, id + 1, lower && i == l, upper && i == r, s, t)) {
			return f[remain][id][lower][upper] = 1;
		}
	}
	return f[remain][id][lower][upper] = 0;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	ll l, r;
	string s, t;
	int res = 0;

	cin >> l >> r;
	memset(f, -1, sizeof(f));
	s = to_string(l);
	t = to_string(r);
	while (s.length() < t.length()) {
		s = '0' + s;
	}
	for (int i = 1; i <= 9*t.length(); i++) {
		for (int j = 1; j <= 9; j++) {
			if (i >= j && j >= s[0] - '0' && j <= t[0] - '0') {
				if (exists(i - j, 1, j == s[0] - '0', j == t[0] - '0', s, t)) {
					// cout << i << " " << j << " " << s << " " << t << "\n";
					res++;
					break;
				}
			}
		}
	}
	cout << res;
	
	return 0;
}