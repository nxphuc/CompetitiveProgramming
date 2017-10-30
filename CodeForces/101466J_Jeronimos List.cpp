#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e7 + 10;
const int MOD = 3e7;

vector<int> cnt(MAX, 0);
vector<int> a;
int n, m, q, x;

int main(){
	ios::sync_with_stdio(false);

	cin >> n >> m >> q;
	a.resize(n);
	for (int i = 0; i < m; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = m; i < n; i++){
		a[i] = (a[i-m] + a[i-m+1]) % MOD;
		cnt[a[i]]++;
	}
	for (int i = 1; i < MAX; i++)
		cnt[i] += cnt[i-1];
	while (q--){
		cin >> x;
		cout << lower_bound(cnt.begin(), cnt.end(), x) - cnt.begin() << "\n";
	}

	return 0;
}