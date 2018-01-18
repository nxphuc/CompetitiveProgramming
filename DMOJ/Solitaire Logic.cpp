// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// const int MAX = 2e5 + 10;
// const int MOD = 1e9 + 7;
// const int INF = 1e9;
// const double pi = acos(-1.0);
// const double EPS = 1e-6;

// bool mark[2][MAX];
// int l[2], r[2];
// int lft, rht;
// int n;
// map<int,int> rows[2];

// void update(int i, int j, int v) {
// 	if (l[i] > r[i]) return;
// 	rows[i][v] = j;
// 	mark[i][j] = 1;
// 	if (l[i] == j) {
// 		l[i]++;
// 		while (l[1 - i] <= n && lft < v) {
// 			if (rows[1-i].find(lft) != rows[1-i].end()) {
// 				lft++;
// 				continue;
// 			}
// 			if (rows[i].find(lft) != rows[i].end()) {
// 				lft++;
// 				continue;
// 			}
// 			rows[1 - i][lft] = l[1 - i];
// 			mark[1 - i][l[1 - i]] = 1;
// 			l[1 - i]++;
// 			lft++;
// 		}
// 	}
// 	if (r[i] == j) {
// 		r[i]--;
// 		while (r[1 - i] > 0 && rht > v) {
// 			if (rows[1-i].find(rht) != rows[1-i].end()) {
// 				rht--;
// 				continue;
// 			}
// 			if (rows[i].find(rht) != rows[i].end()) {
// 				rht--;
// 				continue;
// 			}
// 			rows[1 - i][rht] = r[1 - i];
// 			mark[1 - i][r[1 - i]] = 1;
// 			r[1 - i]--;
// 			rht--;
// 		}
// 	}
// 	for (int i = 0; i < 1; i++) {
// 		while (l[i] <= n && mark[i][l[i]]) l[i]++;
// 		while (r[i] > 0 && mark[i][r[i]]) r[i]--;
// 	}
// 	if (v == lft) {
// 		lft++;
// 	}
// 	if (v == rht) {
// 		rht--;
// 	}
// }

// int query(int row, int v) {
// 	int x = row, y = 1 - row;
// 	auto it1 = rows[x].lower_bound(v);
// 	auto it2 = rows[y].lower_bound(v);
// 	int hi_val = it1->first;
// 	int hi_pos = it1->second;
// }

// int query(int v) {
// 	if (rows[0].find(v) != rows[0].end() || rows[1].find(v) != rows[1].end()) {
// 		return 1;
// 	}
// 	return queryRow(0, v) + queryRow(1, v);
// }

// int main(){
// 	freopen("test.in", "rt", stdin);
// 	ios::sync_with_stdio(false);

// 	int q, t, i, j, v;

// 	cin >> n >> q;
// 	lft = 1, rht = 2*n;
// 	l[0] = l[1] = 1;
// 	r[0] = r[1] = n;
// 	rows[0][0] = 0;
// 	rows[1][0] = 0;
// 	rows[0][2*n+1] = n+1;
// 	rows[1][n*n+1] = n+1;
// 	while (q--) {
// 		cin >> t;
// 		if (t == 1) {
// 			cin >> i >> j >> v;
// 			update(i-1, j, v);
// 		}
// 		else {
// 			cin >> v;
// 			cout << query(v) << "\n";
// 		}
// 		// cout << "@#@#\n";
// 		// for (int x = 0; x < 2; x++) {
// 		// 	for (auto kvp : rows[x]) {
// 		// 		cout << kvp.first << " - " << kvp.second << "\n";
// 		// 	}
// 		// 	// for (int i = 1; i <= n; i++) {
// 		// 	// 	cout << mark[x][i] << " ";
// 		// 	// }
// 		// 	cout << "---\n";
// 		// }
// 	}
	
// 	return 0;
// }