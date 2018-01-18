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

string l, r, s;

int main(){
	ios::sync_with_stdio(false);
	cin >> l >> r;
	int need = max(l.size(), r.size()) - min(l.size(), r.size());
	for (int i = 0; i < need; i++) s += '0';
	if (l.size() < r.size()) l = s + l;
	else r = s + r;
	int pos = 0;
	for (; pos < l.size(); pos++)
		if (l[pos] != r[pos]) break;
	cout << l.size() - pos << endl;
	return 0;
}