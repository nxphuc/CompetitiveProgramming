#include <bits/stdc++.h>
using namespace std;


const int MAX = 1e6 + 10;

int n;
long long t, s, res;
int l, r;
int a[MAX];

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	while (l <= n){
		if (r > l)
			s -= a[l++];
		else{
			r = ++l;
			s = 0;
		}
		while (r <= n && s + a[r] <= t)
			s += a[r++];
		res += r-l;
	}
	cout << res;

	return 0;
}