#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e4 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

string a[MAX];
int n;

int isPrefix(string s, string t) {
	if (s.length() > t.length()) {
		return s.substr(0, t.length()) == t;
	}
	return t.substr(0, s.length()) == s;
}

int isValid() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (isPrefix(a[i], a[j])) {
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	if (!(1 <= t && t <= 50)) {
		cerr << "gioi han t tao lao";
		return 0;
	}
	for (int cs = 1; cs <= t; cs++) {
		set<string> lst;
		cin >> n;
		if (!(1 <= n && n <= 10000)) {
			cerr << n << "\n";
			cerr << "gioi han n tao lao";
			return 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			// if (lst.find(a[i]) != lst.end()) {
			// 	cerr << "trung tao lao";
			// 	return 0;
			// }
			lst.insert(a[i]);
			if (!(1 <= a[i].length() && a[i].length() <= 10)) {
				cerr << a[i] << " " << a[i].length() << "\n";
				cerr << "do dai chuoi tao lao";
				return 0;
			}
		}
		cout << "Case " << cs << ": " << (isValid() ? "YES\n" : "NO\n");
	}
	
	return 0;
}