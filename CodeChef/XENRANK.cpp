#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	int t;
	long long n, m;

	cin >> t;
	while (t--){
		cin >> n >> m;
		m += n;
		cout << m*(m+1)/2 + n + 1 << "\n";
	}

	return 0;
}