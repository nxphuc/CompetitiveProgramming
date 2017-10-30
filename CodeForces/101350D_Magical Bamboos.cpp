#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int t, n, x, cnt0, cnt1;

	cin >> t;
	while (t--){
		cnt0 = cnt1 = 0;
		cin >> n;
		while (n--){
			cin >> x;
			if (x & 1) cnt1++;
			else cnt0++;
		}
		if (!cnt0 || !cnt1)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}