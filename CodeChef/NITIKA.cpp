#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif

	string s;
	int t, pos;

	cin >> t;
	getline(cin, s);
	while (t--){
		getline(cin, s);
		while ((pos = s.find(' ')) != -1){
			cout << (char)toupper(s[0]) << ". ";
			s = s.substr(pos+1);
		}
		for (char& ch : s) ch = tolower(ch);
		s[0] = toupper(s[0]);
		cout << s << "\n";
	}
	return 0;
}