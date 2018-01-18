#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, u, v, x;
	deque<int> q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}
	while (q.size() > 1) {
		u = q.front(); q.pop_front();
		v = q.front(); q.pop_front();
		cout << "Q " << u << " " << v << "\n";
		cin >> x;
		if (!x) {
			q.push_back(u);
			q.push_front(v);
		}
	}
	cout << "A";
	
	return 0;
}