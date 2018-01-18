#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int INF = 1e9;
typedef long long ll;

ll a[MAX], l[110];
ll f[110][MAX];
int n, k;
ll sum;

int main() {
	// freopen("test", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	for (int i = 1; i <= k; i++) {
		cin >> l[i];
		sum += l[i];
	}
	if (sum > n) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i <= n; i++) {
		f[0][i] = 0;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			f[i][j] = INF;
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			if (l[i] <= j) {
				if (f[i][j] > f[i-1][j - l[i]] + a[j] - a[j - l[i]]) {
					f[i][j] = f[i-1][j - l[i]] + a[j] - a[j - l[i]];
				}
			}
			if (l[i] < j) {
				f[i][j] = min(f[i][j], f[i][j-1]);
			}
		}
	}
	cout << f[k][n];

	return 0;
}