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

	ll h, m, s, tot;
	cin >> h >> m >> s;
	m += s / 60;
	s %= 60;
	h += m / 60;
	m %= 60;
	h %= 12;
	tot = h * 3600 + m * 60 + s;
	tot = tot ? 12 * 3600 - tot : tot;
	h = tot / 3600;
	tot %= 3600;
	m = tot / 60;
	tot %= 60;
	s = tot;

	cout << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << m << ":" << setfill('0') << setw(2) << s << "\n";
	
	return 0;
}