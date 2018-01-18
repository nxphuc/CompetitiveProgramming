#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10;
const long long MOD = 1e9 + 7;

char s[MAX];
long long fwd_hash[MAX], bwd_hash[MAX], power[MAX];
int n;

void prepare() {
	power[0] = 1;
	for (int i = 1; i <= n; i++) {
		assert('a' <= s[i - 1] && s[i - 1] <= 'z');
		fwd_hash[i] = (fwd_hash[i - 1] * 2309 + s[i - 1] - 'a') % MOD;
		power[i] = (power[i - 1] * 2309) % MOD;
	}
	for (int i = n; i > 0; i--) {
		bwd_hash[i] = (bwd_hash[i + 1] * 2309 + s[i - 1] - 'a') % MOD;
	}
}

int isPalin(int l, int r) {
	long long fwd = (fwd_hash[r] - fwd_hash[l - 1] * power[r - l + 1] + MOD * MOD) % MOD;
	long long bwd = (bwd_hash[l] - bwd_hash[r + 1] * power[r - l + 1] + MOD * MOD) % MOD;
	return fwd == bwd;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	scanf("%s", s);
	n = strlen(s);
	prepare();

	int q, l, r;
	scanf("%d", &q);
	if (q < 0) return 0;
	while(q--) {
		scanf("%d%d", &l, &r);
		if (r > n) {
			while (1);
		}
		// assert(0 < l && r <= r && r <= n);
		printf("%d\n", isPalin(l, r) ? 1 : 0);
	}

	return 0;
}