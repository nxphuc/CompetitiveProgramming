#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;

int a[MAX];
pair<int,int> l[MAX];
pair<pair<int,int>, int> queries[MAX];
int f[MAX];
int BIT[MAX];
int n, q;

void setBit(int id, int val) {
	while (id < MAX) {
		BIT[id] += val;
		id += id & -id;
	}
}

int getBit(int id) {
	int ret = 0;
	while (id) {
		ret += BIT[id];
		id -= id & -id;
	}
	return ret;
}

void preprocess() {
	stack<int> st;
	a[0] = n + 1;
	st.push(0);
	for (int i = 1; i <= n; i++) {
		while (a[st.top()] < a[i]) {
			st.pop();
		}
		l[i].first = st.top();
		l[i].second = i;
		st.push(i);
	}
	sort(l + 1, l + n + 1);
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> queries[i].first.first >> queries[i].first.second;
		queries[i].second = i;
	}
	preprocess();
	sort(queries, queries + q);
	int i = 1;
	for (int j = 0; j < q; j++) {
		while (i <= n && l[i].first < queries[j].first.first) {
			setBit(l[i].second, 1);
			i++;
		}
		f[queries[j].second] = getBit(queries[j].first.second) - getBit(queries[j].first.first - 1);
	}
	for (int i = 0; i < q; i++) {
		cout << f[i] << "\n";
	}

	return 0;
}