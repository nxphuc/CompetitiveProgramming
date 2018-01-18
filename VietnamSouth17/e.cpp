#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define pb push_back

const int MAX = 1e6 + 10;
const int N = 1e3 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int n, m, a[N][N];
int b[5];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int ret = 0;
	int lo = 1, hi = n;
	int ok1, ok2;
	while (lo <= hi) {
		if (lo == hi) ok1 = 1;
		else ok1 = 0;
		int lo2 = 1, hi2 = m;
		while (lo2 <= hi2) {
			if (lo2 == hi2) ok2 = 1;
			else ok2 = 0;
			if (ok1 + ok2 < 2) {
				if (ok1) {
					if (a[lo][lo2] != a[lo][hi2]) ret++;
				} else if (ok2) {
					if (a[lo][lo2] != a[hi][lo2]) ret++;
				} else {
					b[0] = a[lo][lo2];
					b[1] = a[lo][hi2];
					b[2] = a[hi][lo2];
					b[3] = a[hi][hi2];
					sort(b, b + 4);
					int u = 0, x = 0;
					while (u < 4) {
						int v = u;
						while (v + 1 < 4 && b[v + 1] == b[u]) v++;
						if (v - u + 1 > x) x = v - u + 1;
						u = v + 1;
					}
					ret += 4 - x;
				}
			}
			lo2++, hi2--;
		}
		lo++, hi--;
	}
	cout << ret << endl;
	return 0;
}