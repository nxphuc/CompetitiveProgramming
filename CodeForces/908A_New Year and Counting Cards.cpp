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

	string pat = "aeiou13579";
	string s;
	int cnt = 0;
	cin >> s;
	for (char ch : s) {
		cnt += pat.find(ch) != string::npos;
	}
	cout << cnt;
	
	return 0;
}