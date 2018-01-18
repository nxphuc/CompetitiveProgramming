#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

int query(int n) {
	cout << "Q " << n << "\n";
	cin >> n;
	return n;
}

int countTrailingZeros(int n) {
	int res = 0;
	while (n) {
		res += n/5;
		n /= 5;
	}
	return res;
}

void answer(int n) {
	int lo = 5, hi = 1e5;
	int mi, res = 5;
	while (lo <= hi) {
		mi = (lo + hi) / 2;
		if (countTrailingZeros(mi) >= n) {
			res = mi;
			hi = mi - 1;
		}
		else {
			lo = mi + 1;
		}
	}
	cout << "A " << res;
}

int main(){
	ios::sync_with_stdio(false);

	int lo = 0, hi = 1e6;
	int mi, res = 0;
	while (lo <= hi) {
		mi = (lo + hi) / 2;
		if (query(mi)) {
			res = mi;
			lo = mi + 1;
		}
		else {
			hi = mi - 1;
		}
	}
	answer(res);
	
	return 0;
}