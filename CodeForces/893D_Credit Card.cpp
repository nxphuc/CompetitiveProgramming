#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

typedef long long ll;

int n, d;
int res, bonus, total;
int cur_balance;
multiset<int> my_set;
int a[MAX];

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
		if (total > d) {
			cout << "-1";
			return 0;
		}
		my_set.insert(total);
	}
	total = 0;
	res = 0;
	for (int i = 0; i < n; i++) {
		// cout << "@ " << i << endl;
		if (!a[i]) {
			if (cur_balance < 0) {
				int cur_max = *my_set.rbegin();
				int can_add = d - cur_max - bonus;
				bonus += can_add;
				cur_balance += can_add;
				res++;
				if (cur_balance < 0) {
					cout << -1;
					return 0;
				}
			}
		}
		else {
			cur_balance += a[i];
			if (cur_balance > d) {
				cout << -1;
				return 0;
			}
		}
		total += a[i];
		auto it = my_set.find(total);
		my_set.erase(it);
	}
	cout << res;

	return 0;
}