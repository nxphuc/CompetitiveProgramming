#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	int t, n;
	long long a[110] = {1, 2, 4};

	for (int i = 3; i < 100; i++)
		a[i] = a[i-1] + 3;

	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";
	}

	return 0;
}