#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	vector<int> a;
	
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int flag = 1;
		if (i) {
			flag &= a[i] - a[i-1] > k;
		}
		if (i < n-1) {
			flag &= a[i+1] - a[i] > k;
		}
		cnt += flag;
	}
	cout << cnt;
	return 0;
}