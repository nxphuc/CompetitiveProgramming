#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	int n, x, y, s = 0, res = -1;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		s += x;
	}
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		if (s <= y){
			res = max(x, s);
			break;
		}
	}
	cout << res;

	return 0;
}