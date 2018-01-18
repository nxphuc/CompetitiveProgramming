#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

struct Problem {
	int lim, time, index;

	Problem(int lim = 0, int time = 0, int index = 0) : lim(lim), time(time), index(index) {}
};

int n, t;
Problem a[MAX], b[MAX];
vector<int> f;
int res;

int cmpLim(const Problem& a, const Problem& b) {
	return a.lim > b.lim;
}

int cmpTime(const Problem& a, const Problem& b) {
	return a.time < b.time;
}

int canGet(int point) {
	int m = 0;
	while (m < n && a[m].lim >= point) {
		b[m] = a[m];
		m++;
	}
	if (m < point) {
		return 0;
	}
	sort(b, b+m, cmpTime);
	ll tot = 0;
	for (int i = 0; i < point; i++) {
		tot += b[i].time;
	}
	if (tot > t) {
		return 0;
	}
	f.clear();
	for (int i = 0; i < point; i++) {
		f.push_back(b[i].index);
	}
	return 1;
}

void binarySearch() {
	int lo = 0, hi = n;

	while (lo <= hi) {
		int mi = (lo + hi) / 2;
		if (canGet(mi)) {
			res = mi;
			lo = mi + 1;
		}
		else {
			hi = mi - 1;
		}
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> a[i].lim >> a[i].time;
		a[i].index = i+1;
	}
	sort(a, a + n, cmpLim);
	binarySearch();
	cout << res << "\n";
	cout << f.size() << "\n";
	for (int id : f) {
		cout << id << " ";
	}
	
	return 0;
}