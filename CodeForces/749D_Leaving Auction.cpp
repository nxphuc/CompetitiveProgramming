#include <bits/stdc++.h>
using namespace std;

const int MAX = 200100;

int a[MAX], b[MAX], c[MAX];
int numType[MAX];
vector<int> f[MAX];
int n, q, k;

void process(){
	int M, L = 1, R = n, ans = n;
	int tot;

	while (L <= R){
		M = (L + R)/2;
		tot = 0;
		for (int i = 0; i < k; i++){
//            if (f[c[i]].size())
//                cout << "@@ " << f[c[i]][f[c[i]].size() - 1] << "\n";
			if (f[c[i]].size() && f[c[i]][f[c[i]].size() - 1] >= M)
				tot++;
		}
		if (numType[M] - tot == 1)
			ans = M;
		if (numType[M] - tot == 0)
			R = M-1;
		else
			L = M+1;
	}
	cout << ans << " " << a[ans] << " " << b[ans] << "\n";
}

int main(){
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		f[a[i]].push_back(i);
	}

	memset(c, 0, sizeof(c));
	for (int i = n; i > 0; i--)
		if (!c[a[i]]){
			numType[i] = numType[i+1] + 1;
			c[a[i]] = 1;
		}
		else
			numType[i] = numType[i+1];

	cin >> q;
	while (q--){
		cin >> k;
		for (int i = 0; i < k; i++)
			cin >> c[i];
		process();
	}

	return 0;
}
