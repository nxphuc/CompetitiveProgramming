#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

struct Card {
	int color[3];
	int id;

	Card(int r = 0, int g = 0, int b = 0, int id = 0) : id(id) {
		color[0] = r;
		color[1] = g;
		color[2] = b;
	}
};

Card a[MAX];
int id[MAX];
int lft[3][MAX], rht[3][MAX];
int f[MAX];
int col;
int n;
set<pair<pair<int,int>,int>> st;

int cmp(int x, int y) {
	return a[x].color[col] < a[y].color[col];
}

void process(int i) {
	if (st.find(make_pair(make_pair(f[i], -a[i].id), i)) != st.end()) {
		st.erase(make_pair(make_pair(f[i], -a[i].id), i));
	}
	f[i] = 0;
	for (int col = 0; col < 3; col++) {
		int prv = lft[col][i];
		int nxt = rht[col][i];
		if (a[prv].color[col] == a[i].color[col] || a[i].color[col] == a[nxt].color[col]) {
			continue;
		}
		int angle = a[i].color[col] - a[prv].color[col];
		if (angle < 0) {
			angle += 360;
		}
		f[i] += angle;
		angle = a[nxt].color[col] - a[i].color[col];
		if (angle < 0) {
			angle += 360;
		}
		f[i] += angle;
	}
	st.insert(make_pair(make_pair(f[i], -a[i].id), i));
}

void update(int i) {
	if (st.find(make_pair(make_pair(f[i], -a[i].id), i)) != st.end()) {
		st.erase(make_pair(make_pair(f[i], -a[i].id), i));
	}
	for (col = 0; col < 3; col++) {
		rht[col][lft[col][i]] = rht[col][i];
		lft[col][rht[col][i]] = lft[col][i];
		process(lft[col][i]);
		process(rht[col][i]);
	}
}

int main() {
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i].color[j];
		}
		cin >> a[i].id;
		id[i] = i;
	}
	for (col = 0; col < 3; col++) {
		sort(id, id + n);
		for (int i = 0; i < n; i++) {
			lft[col][id[i]] = id[(i - 1 + n) % n];
			rht[col][id[i]] = id[(i + 1) % n];
		}
	}
	for (int i = 0; i < n; i++) {
		process(i);
	}
	for (int i = 0; i < n; i++) {
		cout << a[st.begin()->second].id << "\n";
		update(st.begin()->second);
	}

	return 0;
}