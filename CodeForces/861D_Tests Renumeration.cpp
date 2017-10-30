#include <bits/stdc++.h>
using namespace std;

string to_String(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

int main() {
	ios::sync_with_stdio(false);
	
	unordered_set<string> sample, regular;
	unordered_set<string> free_sam, free_reg;
	unordered_set<string> need_sam, need_reg;
	vector<pair<string,string>> f;
	string s;
	int n, ty;
	int cnt_sam = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> ty;
		if (ty == 1) {
			sample.insert(s);
			cnt_sam++;
		}
		else {
			regular.insert(s);
		}
	}
	for (int i = 1; i <= n; i++) {
		s = to_String(i);
		if (i <= cnt_sam) {
			if (sample.find(s) != sample.end()) {
				sample.erase(s);
			}
			else {
				if (regular.find(s) == regular.end()) {
					free_sam.insert(s);
				}
				need_sam.insert(s);
			}
		}
		else {
			if (regular.find(s) != regular.end()) {
				regular.erase(s);
			}
			else {
				if (sample.find(s) == sample.end()) {
					free_reg.insert(s);
				}
				need_reg.insert(s);
			}
		}
	}
	while (sample.size() > 0 || regular.size() > 0) {
		int flag = 0;
		while (free_sam.size() > 0) {
			f.push_back(make_pair(*sample.begin(), *free_sam.begin()));
			if (need_reg.find(*sample.begin()) != need_reg.end()) {
				free_reg.insert(*sample.begin());
			}
			sample.erase(sample.begin());
			free_sam.erase(free_sam.begin());
			flag = 1;
		}
		while (free_reg.size() > 0) {
			f.push_back(make_pair(*regular.begin(), *free_reg.begin()));
			if (need_sam.find(*regular.begin()) != need_sam.end()){
				free_sam.insert(*regular.begin());
			}
			regular.erase(regular.begin());
			free_reg.erase(free_reg.begin());
			flag = 1;
		}
		if (flag) continue;
		if (sample.size() > 0) {
			f.push_back(make_pair(*sample.begin(), "nxphu1"));
			free_reg.insert(*sample.begin());
			sample.erase(sample.begin());
			sample.insert("nxphu1");
			continue;
		}
		if (regular.size() > 0) {
			f.push_back(make_pair(*regular.begin(), "nxphu2"));
			free_sam.insert(*regular.begin());
			regular.erase(regular.begin());
			regular.insert("nxphu2");
		}
	}
	cout << f.size() << "\n";
	for (auto& e : f) {
		cout << "move " << e.first << " " << e.second << "\n";
	}

	return 0;
}