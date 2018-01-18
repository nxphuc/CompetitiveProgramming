#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

vector<int> recipes[MAX];
int n, d, m;
int a[MAX];
int cnt[MAX];

int check(int id) {
	if (cnt[id]) {
		return 1;
	}
	if (recipes[id].size() == 0) {
		return 0;
	}
	for (int x : recipes[id]) {
		if (cnt[x]) {
			continue;
		}
		int tmp = check(x);
		// cout << x << " " << tmp << "\n";
		if (!cnt[x] && !tmp) {
			return 0;
		}
	}
	return 1;
}

int canMake(int k) {
	memset(cnt, 0, (n+10)*sizeof(int));
	for (int i = 1; i <= k; i++) {
		cnt[a[i]]++;
	}
	// for (int i = 1; i <= n; i++) {
	// 	cout << cnt[i] << " ";
	// }
	// cout << "\n----------------\n";
	return check(1);
}

int solve() {
	int left = 1, right = d;
	int res = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		// cout << "============== " << mid << " =============\n";
		if (canMake(mid)) {
			res = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return res;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> m >> d;
	for (int id, x, k, i = 0; i < m; i++) {
		cin >> id >> k;
		while (k--) {
			cin >> x;
			recipes[id].push_back(x);
		}
	}
	for (int i = 1; i <= d; i++) {
		cin >> a[i];
	}
	cout << solve();
	
	return 0;
}