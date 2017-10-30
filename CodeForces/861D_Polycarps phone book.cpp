#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	unordered_map<string,int> id;
	int n;
	string s, t;
	vector<string> f;

	cin >> n;

	for (int k = 0; k < n; k++){
		cin >> s;
		f.push_back(s);
		for (int i = 0; i < 9; i++) {
			for (int j = i; j < 9; j++) {
				t = s.substr(i, j - i + 1);
				if (id.find(t) == id.end()) {
					id[t] = k;
				}
				else if (id[t] != k) {
					id[t] = -1;
				}
			}
		}
	}
	for (pair<string,int> e : id) {
		if (e.second != -1 && f[e.second].length() > e.first.length()) {
			f[e.second] = e.first;
		}
	}
	for (string& str : f) {
		cout << str << "\n";
	}

	return 0;
}