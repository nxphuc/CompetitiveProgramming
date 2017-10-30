#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	int cnt[110] = {0};
	int n, k, x;
	int res = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> x;
		cnt[x % k]++;
	}
	for (int j, i = 1; ; i++){
		j = k-i;
		if (i == j)
			res += min(cnt[i], 1);
		else
			if (i > j)
				break;
			else
				res += max(cnt[i], cnt[j]);
	}
	cout << res + min(1, cnt[0]);

	return 0;
}