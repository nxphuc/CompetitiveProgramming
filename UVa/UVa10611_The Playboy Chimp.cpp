#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, q, x, pos;
	vector<int> a;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		a.push_back(x);
	}
	cin >> q;
	while (q--){
		cin >> x;
		pos = lower_bound(a.begin(), a.end(), x) - a.begin();
		if (pos == 0)
			cout << "X ";
		else
			cout << a[pos-1] << " ";
		pos = upper_bound(a.begin(), a.end(), x) - a.begin();
		if (pos == n)
			cout << "X\n";
		else
			cout << a[pos] << "\n";
	}

	return 0;
}