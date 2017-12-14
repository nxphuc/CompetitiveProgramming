#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int a[MAX], rev_a[MAX], b[MAX], rev_b[MAX];
int mark[MAX];
int n;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]) {
			rev_a[a[i]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (b[i]) {
			rev_b[b[i]] = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!rev_a[i] && !rev_b[i]) {
			int j = i, k = i;
			while (j && j == k) {
				mark[j] = 1;
				j = a[j];
				k = b[k];
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			if (rev_a[i]) {
				res++;
			}
			if (rev_b[i]) {
				res++;
			}
		}
	}
	cout << res;

	return 0;
}