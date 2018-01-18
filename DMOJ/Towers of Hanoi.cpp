#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

int a[MAX], b[MAX];
int n;
vector<int> f;

void flip(int pos) {
	a[pos] ^= 1;
	a[pos - 1] ^= 1;
	if (pos + 1 < n) {
		a[pos + 1] ^= 1;
	}
}

int tryToSolve(int p = 1) {
	if (p == n) {
		for (int i = 0; i < n; i++) {
			if (a[i]) {
				return 0;
			}
		}
		return 1;
	}

	if (a[p-1]) {
		flip(p);
		f.push_back(p);
	}
	if (!tryToSolve(p+1)) {
		flip(p);
		f.pop_back();
		return 0;
	}
	return 1;
}

void printSolver() {
	cout << f.size() << "\n";
	for (int p : f) {
		cout << p+1 << "\n";
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	if (tryToSolve()) {
		printSolver();
		return 0;
	}

	f.clear();
	for (int i = 0; i < n; i++) {
		a[i] = b[i];
	}
	flip(0);
	f.push_back(0);
	tryToSolve();
	printSolver();
	
	return 0;
}