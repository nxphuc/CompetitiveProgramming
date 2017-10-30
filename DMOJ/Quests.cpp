#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 5010;

ll f[2][MAX];
int g[MAX], h[MAX], q[MAX], t[MAX];
int N, H;
int cost;
ll gain;

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> H;
	for (int i = 1; i <= N; i++) {
		cin >> g[i] >> h[i] >> q[i] >> t[i];
	}
	for (int cur, prv, i = 1; i <= N; i++) {
		cur = i & 1;
		prv = 1 - cur;
		for (int j = 0; j <= H; j++) {
			f[cur][j] = 0;
			if (j >= h[i]) {
				f[cur][j] = max(f[cur][j], f[prv][j - h[i]] + g[i]);
			}
		}
		for (int j = h[i] + t[i]; j <= H; j++) {
			f[cur][j] = max(f[cur][j], f[cur][j - t[i]] + q[i]);
		}
		for (int j = 0; j <= H; j++) {
			f[cur][j] = max(f[cur][j], f[prv][j]);
		}
	}
	gain = 0;
	for (int j = 0; j <= H; j++) {
		gain = max(gain, f[N & 1][j]);
	}
	cout << gain << "\n";

	return 0;
}