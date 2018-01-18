#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define pb push_back

const int MAX = 1e6 + 10;
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int main(){
	ios::sync_with_stdio(false);
	srand(time(NULL));
	int n = 10;
	int k = rand() % n + 1;
	int m = 20;
	cout << n << " " << m << " " << k << endl;
	for (int i = 0; i < m; i++) {
		int x = rand() % n + 1;
		int y = rand() % n + 1;
		cout << x << " " << y;
		x += rand() % (n - x + 1);
		y += rand() % (n - y + 1);
		cout << " " << x << " " << y << endl;
	}
	return 0;
}