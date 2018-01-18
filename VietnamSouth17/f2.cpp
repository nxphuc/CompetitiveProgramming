#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int numDigit(ll n) {
	int res = 0;
	while (n) {
		res++;
		n /= 10;
	}
	return res;
}

vector<int> vis(1000001, -1);
int bfs() {
	vis[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (u+1 <= 1000000 && vis[u+1] == -1) {
			vis[u+1] = vis[u] + 1;
			q.push(u+1);
		}
		string s = to_string(u);
		sort(s.begin(), s.end());
		do {
			if (s[0] != '0') {
				int v = stoi(s);
				if (v <= 1000000 && vis[v] == -1) {
					vis[v] = vis[u] + 1;
					q.push(v);
				}
			}
		} while (next_permutation(s.begin(), s.end()));
	}
}

int solve(ll n) {
	int f[15] = {9, 19, 29, 39, 49, 59, 69, 79, 89, 99};
	ll cur = 1;
	int d = 0;
	int res = 0;

	if (n <= 10) {
		return n - 1;
	}
	while (cur*10 <= n) {
		cur *= 10;
		res += f[d++];
	}
	if (cur == n) {
		return res;
	}
	// cout << res << " " << cur << " " << d << "\n";
	if(n % cur == 0) {
		res += d*10;
		if (n / cur > 2) {
			res += n/cur - 1;
		}
		return res;
	}
	string s = to_string(n);
	string t = to_string(cur);
	int i = 0;
	int flag = 0;
	// cout << res << " " << s << " " << t << "\n";
	while (i < s.length()) {
		if (s[i] != t[i]) {
			if (i == 0) {
				if (s.find('1') != string::npos) {
					swap(t[s.find('1')], t[0]);
				}
			}
			// cout << i << " " << s[i] << " " << t[i] << " " << t[t.length() - 1] << "\n";
			if (s[i] != t[t.length() - 1]) {
				res += s[i] - t[t.length() - 1];
				t[t.length() - 1] = s[i];
				flag = 1;
			}
			if (i < t.length() - 1) {
				swap(t[i], t[t.length() - 1]);
				if (flag) {
					res++;
					flag = 0;
				}
			}
		}
		i++;
		// cout << res << " " << s << " " << t << "\n";
	}
	// cout << res << " " << s << " " << t << "\n";
	// for (int i = 1; i < s.length(); i++) {
	// 	if (t.find(s[i], 1) != string::npos) {
	// 		t.erase(t.find(s[i], 1), 1);
	// 		s.erase(i, 1);
	// 		i--;
	// 	}
	// }
	// // cout << res << " " << s << " " << t << "\n";
	// for (int i = 0; i < s.length(); i++) {
	// 	if (s[i] != t[i]) {
	// 		res += s[i] - t[i] + 1;
	// 	}
	// }
	// // cout << res << " " << s << " " << t << "\n";
	// if (s.find('1', 1) != string::npos && s.find('1', 1) < s.length() - 1) {
	// 	res--;
	// }
	// if (n % 10) {
	// 	res--;
	// }
	return res;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	ll t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		cout << solve(n) << "\n";
	}
	// freopen("test.ou", "wt", stdout);
	// bfs();
	// for (int i = 1; i <= 1000000; i++) {
	// 	int u = vis[i];
	// 	int v = solve(i);
	// 	if (u != v) {
	// 		cout << i << " " << u << " " << v << "\n";
	// 	}
	// }

	return 0;
}