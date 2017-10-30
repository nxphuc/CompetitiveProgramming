#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	long long m = n;
	int cnt2 = 0, cnt5 = 0;
	while (n % 2 == 0) {
		n /= 2;
		cnt2++;
	}
	while (n % 5 == 0) {
		n /= 5;
		cnt5++;
	}
	while (cnt2 < k) {
		m *= 2;
		cnt2++;
	}
	while (cnt5 < k) {
		m *= 5;
		cnt5++;
	}
	cout << m;

	return 0;
}