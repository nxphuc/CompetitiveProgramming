#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;

bool is_prime[MAX];

void sieve() {
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < MAX; i++) {
		if (is_prime[i]) {
			for (long long j = 1LL*i*i; j < MAX; j += i) {
				is_prime[j] = false;
			}
		}
	}
}

int main() {
	freopen("input17.txt", "rt", stdin);
	freopen("output17.txt", "wt", stdout);
	ios::sync_with_stdio(false);

	sieve();
	int t, n;
	int line = 0;
	scanf("%d", &t);
	while (t--) {
		line++;
		scanf("%d", &n);
		if (!(0 < n)) {
			cerr << line << "\n";
		}
		if (n == 0) {
			printf("1\n");
			continue;
		}
		printf("%d\n", (is_prime[n - 1] || is_prime[n] || is_prime[n + 1]) ? 1 : 0);
	}

	return 0;
}