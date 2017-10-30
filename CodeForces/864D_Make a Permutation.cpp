#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int n, res;
int a[MAX], cnt[MAX];
int fix[MAX];
set<int> missing;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) {
			missing.insert(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] > 1 || fix[a[i]]) {
			if (fix[a[i]] || (*missing.begin() < a[i])) {
				cnt[a[i]]--;
				a[i] = *missing.begin();
				missing.erase(missing.begin());
				res++;
				fix[a[i]] = 1;
			}
			else {
				fix[a[i]] = 1;
			}
		}
	}
	// for (int i = n; i >= 0; i--) {
	// 	if (cnt[a[i]] > 1) {
	// 		cnt[a[i]]--;
	// 		a[i] = *missing.rbegin();
	// 		missing.erase(a[i]);
	// 		res++;
	// 	}
	// }
	cout << res << "\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}