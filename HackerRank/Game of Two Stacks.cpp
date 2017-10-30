#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int t, n, m;
long long res, sum, x;
int a[MAX], b[MAX];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> m >> x;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < m; i++)
			cin >> b[i];
		sum = 0;
		int j = 0;
		while (j < m && sum + b[j] <= x) sum += b[j++];
		res = j;
		for (int i = 0; i < n; i++){
			sum += a[i];
			while (sum > x && j >= 0) sum -= b[--j];
            if (sum <= x)
                res = max(res, 1LL + i + j);
            else
                break;
		}

		cout << res << "\n";
	}
	return 0;
}