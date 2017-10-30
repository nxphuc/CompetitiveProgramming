#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	ll n, m, k;

	cin >> n >> k;
	m = sqrt(2*k);
	if (m * (m + 1) <= 2*k) {
		m++;
	}
	if (n * (n - 1) < 2*k) {
		cout << "Impossible";
		return 0;
	}
	ll need = k - m * (m - 1) / 2;
	for (int i = 0; i < need; i++) {
		cout << "(";
	}
	if (need){
		cout << "()";
	}
	for (int i = need; i < m; i++) {
		cout << "(";
	}
	for (int i = 0; i < m; i++) {
		cout << ")";
	}
	for (int i = m + (need > 0); i < n; i++) {
		cout << "()";
	}

	return 0;
}