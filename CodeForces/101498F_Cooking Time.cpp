#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
const int N = 1e5 + 10;

using namespace std;

int nxt[N];
map<int, int> f;
int n, a[N], test, k;

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);
	cin >> test;
	while (test--) {
		cin >> n >> k;
		f.clear();
		memset(nxt, 0, sizeof(nxt));
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (f[a[i]]) nxt[f[a[i]]] = i;
			f[a[i]] = i;
		}
		for (int i = 1; i <= n; i++)
			if (nxt[i] == 0) nxt[i] = n + 1;
		f.clear();
		set<int> p;
		int res = 0, cur = 0;
		for (int i = 1; i <= n; i++) {
			if (p.find(i) != p.end()) {
				p.erase(i);
				p.insert(nxt[i]);
			}
			else {
				if (p.size() == k) {
					p.erase(*p.rbegin());
				}
				p.insert(nxt[i]);
				res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}