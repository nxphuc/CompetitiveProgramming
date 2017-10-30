#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int t, n;

	cin >> t;
	while (t--){
		cin >> n;
		if (n/2 == 1)
			cout << "second\n";
		else
			cout << "first\n";
	}
	return 0;
}