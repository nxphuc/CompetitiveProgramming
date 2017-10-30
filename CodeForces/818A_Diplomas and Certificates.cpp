#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	long long n, m, k;

	cin >> n >> k;
	m = n/2/(k+1);
	cout << m << " " << k*m << " " << n - (k+1)*m << "\n";

	return 0;
}