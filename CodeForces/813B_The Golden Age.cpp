#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	long long x, y, l, r;
	long long nx = 1, ny = 1;
	vector<long long> a;

	cin >> x >> y >> l >> r;
	for (int i = 0; i < 60; i++){
		if (i){
			if (nx > r/x)
				break;
			nx *= x;
		}
		ny = 1;
		if (l <= nx + ny && nx + ny <= r)
			a.push_back(nx + ny);
		for (int j = 1; j < 60; j++){
			if (ny > r/y)
				break;
			ny *= y;
			if (l <= nx + ny && nx + ny <= r)
				a.push_back(nx + ny);
		}
	}
	a.push_back(l-1);
	a.push_back(r+1);
	sort(a.begin(), a.end());
	x = 0;
	for (int i = 1; i < a.size(); i++)
		x = max(x, a[i] - a[i-1] - 1);
	cout << x;

	return 0;
}