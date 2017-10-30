#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	int a[110] = {0}, cnt[110] = {0};
	int cur, last, x;
	int n, m;

	cin >> n >> m;
	cin >> last;
	for (int i = 1; i < m; i++){
		cin >> cur;
		x = cur - last;
		if (x <= 0) x += n;
		if (a[last] && a[last] != x){
			cout << -1;
			return 0;
		}
		a[last] = x;
		last = cur;
	}
	
	for (int i = 1; i <= n; i++){
		cnt[a[i]]++;
		if (a[i] && cnt[a[i]] > 1){
			cout << -1;
			return 0;
		}
	}
	for (int i = 1, j = 1; i <= n; ){
		if (a[i])
			i++;
		else
			if (cnt[j])
				j++;
			else{
				a[i++] = j++;
			}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";

	return 0;
}