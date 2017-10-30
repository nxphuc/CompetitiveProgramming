#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> points;
map<int,int> cnt;

int isValid(int new_point) {
	map<int,int> cnt2;
	for (int point : points) {
		cnt2[abs(new_point - point)]++;
	}
	for (const auto& kvp : cnt2) {
		if (cnt.find(kvp.first) == cnt.end() || cnt[kvp.first] < kvp.second) {
			return 0;
		}
	}
	return 1;
}

void addPoint(int new_point) {
	for (int point : points) {
		cnt[abs(new_point - point)]--;
		if (cnt[abs(new_point - point)] == 0) {
			cnt.erase(abs(new_point - point));
		}
	}
	points.push_back(new_point);
}

void removePoint() {
	int tmp = *points.rbegin();
	points.pop_back();
	for (int point : points) {
		cnt[abs(tmp - point)]++;
	}
}

int rec() {
	if (points.size() == n) {
		return 1;
	}
	int new_point = cnt.rbegin()->first;
	if (isValid(new_point)) {
		addPoint(new_point);
		if (rec()) {
			return 1;
		}
		removePoint();
	}
	new_point = points[1] - new_point;
	if (isValid(new_point)) {
		addPoint(new_point);
		if (rec()) {
			return 1;
		}
		removePoint();
	}
	return 0;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t;

	cin >> t;
	while (t--) {
		cin >> n;

		cnt.clear();
		points.clear();
		for (int x, m = n*(n-1)/2, i = 0; i < m; i++) {
			cin >> x;
			cnt[x]++;
		}
		
		points.push_back(0);
		points.push_back(cnt.rbegin()->first);
		cnt[points[1]]--;
		if (cnt[points[1]] == 0) {
			cnt.erase(points[1]);
		}
		rec();
		sort(points.begin(), points.end());
		for (int p : points) {
			cout << p << " ";
		}
		cout << "\n";
	}

	return 0;
}