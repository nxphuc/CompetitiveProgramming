#include <bits/stdc++.h>

using namespace std;

int main() {
	string s, res;
	vector<int> pos[2];
	int n;
	
	cin >> n;
	cin >> res;
	pos[0].push_back(0);
	for (int i = 1; i < n; i++) {
		cin >> s;
		int cur_id = i & 1;
		int prev_id = 1 - cur_id;
		char min_char = s[pos[prev_id][0]];
		pos[cur_id].clear();
		for (auto p : pos[prev_id]) {
			for (int j = 0; j < 2; j++) {
				if (s[p + j] < min_char) {
					pos[cur_id].clear();
					min_char = s[p + j];
				}
				if (s[p + j] == min_char && (pos[cur_id].size() == 0 || pos[cur_id][pos[cur_id].size() - 1] != p + j)) {
					pos[cur_id].push_back(p + j);
				}
			}
		}
		res += min_char;
	}
	cout << res;
	return 0;
}