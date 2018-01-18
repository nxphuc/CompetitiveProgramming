#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e4 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

string a[MAX];

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n;
	cin >> t;
	for (int cs = 1; cs <= t; cs++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int flag = 0;
		for (int i = 1; i < n; i++) {
			if (a[i-1].length() <= a[i].length() && a[i-1] == a[i].substr(0, a[i-1].length())) {
				flag = 1;
				break;
			}
		}
		cout << "Case " << cs << ": " << (flag ? "NO\n" : "YES\n");
	}
	
	return 0;
}