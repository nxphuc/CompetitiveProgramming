#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int mn = 1010, mx = -1010;
	int n, x;
	cin >> n;
	cin >> mx;
	mn = mx;
	n--;
	while (n--){
		cin >> x;
		mn = min(mn, x);
		mx = max(mx, x);
	}	
	cout << mx - mn;

	return 0;
}
