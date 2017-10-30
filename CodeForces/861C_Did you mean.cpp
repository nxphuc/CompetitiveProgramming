#include <bits/stdc++.h>
using namespace std;

int isVowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
	ios::sync_with_stdio(false);

	string s, t;
	int cnt, is_same = -1;
	cin >> s;
	t = "";
	cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (isVowel(s[i])) {
			is_same = -1;
			cnt = 0;
			t += s[i];
		}
		else {
			if (is_same == -1) {
				is_same = 1;
				cnt = 1;
				t += s[i];
			}
			else {
				is_same &= s[i] == s[i-1];
				cnt++;
				if (cnt >= 3 && !is_same) {
					cout << t << " ";
					t = s[i];
					is_same = 1;
					cnt = 1;
				}
				else {
					t += s[i];
				}
			}
		}
	}
	cout << t;

	return 0;
}