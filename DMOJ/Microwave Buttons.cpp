#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

int buttons[10] = {0};

int getTime(int h, int m, int s) {
	return h*3600 + m*60 + s;
}

string toString(int n) {
	string s = to_string(n);
	if (n < 10) {
		s = "0" + s;
	}
	return s;
}

int valid(int n) {
	string s = toString(n);
	for (char ch : s) {
		if (!buttons[ch - '0']) {
			return 0;
		}
	}
	return 1;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	string s, t;
	getline(cin, s);
	getline(cin, t);
	for (char ch : t) {
		buttons[ch - '0'] = 1;
	}
	int time_s = getTime(stoi(s.substr(0, 2)),
						stoi(s.substr(3, 2)),
						stoi(s.substr(6, 2)));
	int diff = INF;
	t = "00:00:00";
	for (int i = 0; i < 100; i++) {
		if (!valid(i)) continue;
		for (int j = 0; j < 100; j++) {
			if (!valid(j)) continue;
			for (int k = 0; k < 100; k++) {
				if (!valid(k)) continue;
				int tmp = getTime(i, j, k);
				if (abs(time_s - tmp) < diff) {
					diff = abs(time_s - tmp);
					t = toString(i) + ":" + toString(j) + ":" + toString(k);
				}
			}
		}
	}
	cout << t;
	
	return 0;
}