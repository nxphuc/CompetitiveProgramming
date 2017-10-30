#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 1e5 + 10;

int n;
int a[MAX];

ll kadane(){
	ll cur = 0, mx = -1e12;

	for (int i = 0; i < n; i++){
		cur += a[i];
		mx = max(mx, cur);
		if (cur < 0) cur = 0;
	}
	return mx;
}

ll sumPos(){
	ll s = 0;
	int mx = -1e9;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		if (a[i] >= 0){
			cnt++;
			s += a[i];
		}
		mx = max(mx, a[i]);
	}

	if (!cnt) return mx;
	return s;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << kadane() << " " << sumPos() << "\n";

	return 0;
}