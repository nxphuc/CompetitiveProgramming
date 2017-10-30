#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int t, n, res, id, rid, x;
int BIT[2][MAX];
int a[MAX];
int b[MAX];

void update(int BIT[], int id, int val){
	while (id <= n){
		BIT[id] = max(BIT[id], val);
		id += id & (-id);
	}
}

int getMax(int BIT[], int id){
	int res = 0;
	while (id){
		res = max(res, BIT[id]);
		id -= id & (-id);
	}
	return res;
}

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> t;
	for (int cs = 1; cs <= t; cs++){
		memset(BIT, 0, sizeof(BIT));
		res = 0;

		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b+1, b+n+1);
		for (int i = 1; i <= n; i++){
			id = lower_bound(b+1, b+n+1, a[i]) - b;
			rid = n - id + 1;
			x = getMax(BIT[0], id - 1);
			if (x > 0){
				update(BIT[1], rid, x+1);
				res = max(res, x+1);
			}
			x = getMax(BIT[1], rid - 1);
			update(BIT[0], id, x+1);
		}
		cout << "Case #" << cs << "\n" << res << "\n";
	}

	return 0;
}