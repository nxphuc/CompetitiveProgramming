#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;
vector<int> res;
int n;

int rec(int id, int is_greater) {
	if (id > n) {
		return is_greater || a < b;
	}
	if (b[id] != -1) {
		if (!is_greater && b[id] < a[id]) {
			return 0;
		}
		return rec(id+1, is_greater || b[id] > a[id]);
	}
	for (int i = is_greater ? 1 : a[id]; i <= n; i++) {
		if (b[i] == -1) {
			b[id] = i;
			b[i] = id;
			if (rec(id+1, is_greater || b[id] > a[id])) {
				return 1;
			}
			b[i] = b[id] = -1;
		}
	}
	return 0;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	a.assign(n+1, 0);
	b.assign(n+1, -1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = a[1]; i <= n; i++) {
		b[1] = i;
		b[i] = 1;
		if (rec(1, i > a[1])) {
			break;
		}
		b[1] = b[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		cout << b[i] << " ";
	}

	return 0;
}