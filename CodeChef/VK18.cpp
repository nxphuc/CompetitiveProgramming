#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const int MAX = 1e6 + 10;

ll f[MAX];
ll s[MAX];

int numDiamonds(int n) {
	string s = to_string(n);
	int sum[2] = {0};
	for (int i = 0; i < s.length(); i++) {
		sum[s[i] & 1] += s[i] - '0';
	}
	return abs(sum[0] - sum[1]);
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	s[1] = f[1] = 2;
	ll cur = 2;
	for (int i = 2; i <= 1e6; i++) {
		s[i] = s[i-1] + numDiamonds(2*i);
		cur = cur - numDiamonds(i) + numDiamonds(2*i-1) + numDiamonds(2*i);
		f[i] = f[i-1] + cur;
	}

	// ll cur_sum = 0;
	// for (int i = 1; i <= 10000; i++) {
	// 	for (int j = 1; j <= i; j++) {
	// 		cur_sum += numDiamonds(i+j);
	// 	}
	// 	assert(f[i] == cur_sum);
	// }
	// cout << f[1000000] << "\n";

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << 2*f[n] - s[n] << "\n";
	}

	return 0;
}