#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2e4 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

string s[MAX];
vector<pair<int,int>> f;
set<string> lst;

void move(string s, string t, string pre) {
	int n = s.length();
	if (n == 0) {
		return;
	}
	// cerr << "@ " << pre + s << " " << s << " " << t << "\n";
	lst.erase(pre + s);
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			string tmp(n-i-1, char(150 - s[i] - t[i]));
			move(s.substr(i+1), tmp, pre + s.substr(0, i+1));
			f.push_back(make_pair(s[i] - '0', t[i] - '0'));
			move(tmp, t.substr(i+1), pre + t.substr(0, i+1));
			break;
		}
	}
}

int cmp(string s, string t) {
	return s < t;
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou2", "wt", stdout);
	ios::sync_with_stdio(false);

	int n, q;

	cin >> n >> q;
	s[0].resize(n, '1');
	for (int i = 1; i <= q; i++) {
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
		lst.insert(s[i]);
	}
	sort(s + 1, s + q + 1, cmp);
	string cur = s[0];
	string pre = "";
	for (int i = 1; i <= q; i++) {
		if (lst.find(s[i]) != lst.end()) {
			move(cur, s[i], pre);
			cur = s[i];
		}
	}
	vector<pair<int,int>> g = f;
	if (q > 7000) {
		for (int tt = 0; tt < 5; tt++) {
			random_shuffle(s + 1, s + q + 1);
			f.clear();
			for (int i = 1; i <= q; i++) {
				lst.insert(s[i]);
			}
			cur = s[0];
			for (int i = 1; i <= q; i++) {
				if (lst.find(s[i]) != lst.end()) {
					move(cur, s[i], pre);
					cur = s[i];
				}
			}
			if (f.size() < g.size()) {
				g = f;
			}
		}
	}
	cout << g.size() << "\n";
	for (auto p : g) {
		cout << p.first << " " << p.second << "\n";
	}
	
	return 0;
}