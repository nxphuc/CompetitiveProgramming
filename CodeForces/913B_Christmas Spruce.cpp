#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

vector<int> child[MAX];
int is_leaf[MAX];
int n;

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int x, i = 2; i <= n; i++) {
		cin >> x;
		child[x].push_back(i);
	}
	for (int i = n; i >= 1; i--) {
		if (child[i].size()) {
			int cnt = 0;
			for (int v : child[i]) {
				if (is_leaf[v]) {
					cnt++;
				}
			}
			if (cnt < 3) {
				cout << "No";
				return 0;
			}
		}
		else {
			is_leaf[i] = 1;
		}
	}
	cout << "Yes";
	
	return 0;
}