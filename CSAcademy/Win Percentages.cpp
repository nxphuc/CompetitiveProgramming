#include <bits/stdc++.h>

using namespace std;

int main() {
	int g1, g2, p1, p2;
	cin >> g1 >> p1 >> g2 >> p2;
	int w1 = g1 * p1 / 100;
	while (w1 * 100 < g1 * p1) {
		w1++;
	}
	assert(w1 <= g1);
	assert(100.0*w1/g1 >= p1);
	int w2 = (p2 + 1) * g2 / 100;
	while (w2 * 100 >= g2 * (p2 + 1)) {
		w2--;
	}
	assert(w1 <= w2);
	assert(w2 <= g2);
	assert(100.0*w2/g2 >= p2);
	assert(100.0*w2/g2 < p2+1);
	cout << min(w2 - w1, g2 - g1);
	return 0;
}