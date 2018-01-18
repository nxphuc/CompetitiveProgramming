#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	int a, b, c, d;
	int cnt[210] = {0};
	int res = 0;

	cin >> a >> b >> c >> d;
	for (int i = a; i <= b; i++)
		for (int j = c; j <= d; j++)
			cnt[i+j]++;
	cin >> a >> b >> c >> d;
	for (int i = a; i <= b; i++)
		for (int j = c; j <= d; j++){
			for (int k = 2; k <= 200; k++){
				if (k < i+j)
					res -= cnt[k];
				if (k > i+j)
					res += cnt[k];
			}
		}
	cout << (res ? (res > 0 ? 1 : 2) : 3);

	return 0;
}