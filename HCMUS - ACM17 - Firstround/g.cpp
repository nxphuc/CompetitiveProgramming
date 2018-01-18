#include <bits/stdc++.h>
using namespace std;

int a[15][15];
vector<int> root[10];
int f[15];

int digitRoot(int n) {
	if (n < 10) {
		return n;
	}
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return digitRoot(sum);
}

int rec(int id) {
	if (id > 9) {
		return 1;
	}
	int val = a[id][id];
	for (const int& x: root[val]) {
		int flag = 1;
		for (int i = 1; i < id; i++) {
			if (digitRoot(f[i] * x) != a[id][i]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			f[id] = x;
			if (rec(id + 1)) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	// freopen("input", "rt", stdin);
	ios::sync_with_stdio(false);

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (a[i][j] != a[j][i]) {
				cout << "failure";
				return 0;
			}
		}
	}
	for (int i = 1; i < 10; i++) {
		root[digitRoot(i*i)].push_back(i);
	}
	if (!rec(1)) {
		cout << "failure";
		return 0;
	}
	for (int i = 2; i < 10; i++) {
		int r = f[i];
		while (f[i] <= f[i-1] || digitRoot(f[i]) != r) {
			f[i]++;
			if (f[i] > 1000) {
				cout << "failure";
				return 0;
			}
		}
	}
	cout << "successful";

	return 0;
}