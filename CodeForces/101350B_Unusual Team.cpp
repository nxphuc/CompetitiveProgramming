#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int t, a, b;

	cin >> t;
	while (t--){
		cin >> a >> b;
		if (a >= b)
			cout << "FunkyMonkeys\n";
		else
			cout << "WeWillEatYou\n";
	}

	return 0;
}