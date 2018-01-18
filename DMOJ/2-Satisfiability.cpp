#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n;
	scanf("%d", &n);
	if (n & 1) {
		printf("$%d.50 $%d.50", n/2, n/2);
	}
	else {
		printf("$%d.00 $%d.00", n/2, n/2);
	}

	return 0;
}