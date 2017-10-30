#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	int t, mn, mx, cur;
	string s;

	cin >> t;
	while (t--){
		cin >> s;
		cur = mn = mx = 1;
		for (char ch: s)
			if (ch == '>'){
				cur--;
				mn = min(mn, cur);
			}
			else
				if (ch == '<'){
					cur++;
					mx = max(mx, cur);
				}
		cout << mx + 1 - mn << "\n";
	}

	return 0;
}