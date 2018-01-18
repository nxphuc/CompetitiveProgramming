#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int INF = 1e9;
typedef long long ll;

int test, n;
int a, b, c, d;

int main() {
	// freopen("test", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c >> d;
	int res = a + b + c + d;
	res -= a - a%2;
	res -= c - c%2;
	res -= min(b, d)*2;
    int x = min(b, d);
    a %= 2;
    c %= 2;
    b -= x;
    d -= x;
    // cout << res << " " << a << " " << b << " " << c << " " << d << "\n";
    if (d && a) {
    	res--;
    	a--;
    	d--;
    }
    if (b && c) {
        res--;
        b--;
        c--;
    }
    if (a && b) {
    	res--;
    }
    if (c && d) {
    	res--;
    }

    cout << res;

	return 0;
}