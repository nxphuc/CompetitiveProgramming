#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif

	int t, n;
	string s;
	
	cin >> t;
	getline(cin, s);
	while (t--){
		getline(cin, s);
		n = s.length();
		for (auto& ch : s)
			if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
				ch += 3;
		reverse(s.begin(), s.end());
		for (int i = n/2; i < n; i++)
			s[i]--;
		cout << s << "\n";
	}

	return 0;
}