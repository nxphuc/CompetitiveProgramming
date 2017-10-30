#include <bits/stdc++.h>
using namespace std;

const int MAX = 2510;

bitset<MAX> a[MAX], f;
int t, n, k, len, x, cnt;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif

	cin >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 0; i < n; i++){
			a[i].reset();
			cin >> len;
			while (len--){
				cin >> x;
				a[i].set(x-1);
			}
		}
		f.reset();
		for (int i = 0; i < k; i++)
			f.set(i);
		cnt = 0;
	   	for (int i = 0; i < n; i++)
	   		for (int j = i+1; j < n; j++)
	   			if ((a[i] | a[j]) == f)
	   				cnt++;
		cout << cnt << "\n";
	}

	return 0;
}