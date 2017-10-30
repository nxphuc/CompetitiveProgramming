#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 10;

int e, n;
int a[MAX];

int doit() {
	sort(a, a+n);
	int lft = 0, rht = n;
	int res = 0;
	while (lft < rht) {
		if (a[lft] < e) {
			e -= a[lft];
			res++;
			lft++;
		}
		else {
			if (!res || lft + 1 == rht) {
				break;
			}
			rht--;
			e += a[rht];
			res--;
		}
	}
	return res;
}

int main() {
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int t;

	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		
		cin >> e >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		cout << "Case #" << cs << ": " << doit() << "\n";
	}

	return 0;
}