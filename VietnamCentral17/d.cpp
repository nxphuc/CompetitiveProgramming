#include <bits/stdc++.h>
using namespace std;

int getDir(int x, int y) {
	if (y) {
		return y > 0 ? 0 : 1;
	}
	return x > 0 ? 2 : 3;
}

/*
	0: up
	1: down
	2: right
	3: left
*/

int turnRight(int prv, int cur) {
	switch (prv) {
		case 0:
			return cur == 2;
		case 1:
			return cur == 3;
		case 2:
			return cur == 1;
		case 3:
			return cur == 0;
	}
	return 0;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, old_x, old_y, new_x, new_y;
	cin >> n;
	cin >> new_x >> new_y;
	cin >> old_x >> old_y;
	int cnt = 0;
	int cur_dir = getDir(old_x - new_x, old_y - new_y);
	for (int i = 2; i < n; i++) {
		cin >> new_x >> new_y;
		int new_dir = getDir(new_x - old_x, new_y - old_y);
		cnt += turnRight(cur_dir, new_dir);
		// cout << cur_dir << " " << new_dir << "\n";
		cur_dir = new_dir;
		old_x = new_x;
		old_y = new_y;
		// cout << cnt << "\n";
	}
	cout << cnt;

	return 0;
}