#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e4 + 10;

int is_prime[MAX];
int f[3][MAX];
vector<int> primes;

void sieve() {
	memset(is_prime, 1, sizeof(is_prime));
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i < MAX; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = i*i; j < MAX; j += i) {
				is_prime[j] = 0;
			}
		}
	}
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	sieve();
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < MAX; j++) {
			f[i][j] = MAX;
		}
	}
	for (int i = 1; i < MAX - 100; i++) {
		if (is_prime[i]) {
			f[0][i] = 1;
			for (int j = i-1; j > 1 && !is_prime[j]; j--) {
				f[0][j] = f[2][j+1];
				f[1][j] = f[0][j+1];
				f[2][j] = f[1][j+1];
				for (const auto & p : primes) {
					if (p > j) {
						break;
					}
					if (j % p == 0 && min(f[2][j/p], j/p) <= f[0][j]) {
						f[0][j] = min(f[2][j / p], j/p);
						f[1][j] = f[0][j / p];
						f[2][j] = f[1][j / p];
					}
				}
			}
		}
	}
	for (int i = 1; i < MAX; i++) {
		for (int j = 0; j < 3; j++) {
			f[j][i] = min(f[j][i], i);
		}
	}

	int t, k;
	string s;
	int odd = 0, even = 0, ingmariay = 0;

	// for (int i = 1; i <= 10; i++) {
	// 	for (int j = 0; j < 3; j++) {
	// 		cout << f[j][i] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cin >> t;
	while (t--) {
		cin >> s >> k;
		if (s == "O") {
			odd += f[0][k];
			even += f[1][k];
			ingmariay += f[2][k];
		}
		else {
			if (s == "E") {
				odd += f[2][k];
				even += f[0][k];
				ingmariay += f[1][k];
			}
			else {
				odd += f[1][k];
				even += f[2][k];
				ingmariay += f[0][k];
			}
		}
	}
	cout << odd << " " << even << " " << ingmariay;

	return 0;
}