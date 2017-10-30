#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;

map<char,int> mp;
int f[MAX];
int t, n, c, res;
string s;
stack< pair<int, int> > st;
pair<int,int> tmp;

int main(){
	// #ifdef LOCAL_DEBUG
	//	freopen("test.in", "rt", stdin);
	// #endif
	ios::sync_with_stdio(false);

	mp['('] = 1;
	mp[')'] = -1;
	mp['['] = 2;
	mp[']'] = -2;
	mp['{'] = 3;
	mp['}'] = -3;

	cin >> t;
	for (int cs = 1; cs <= t; cs++){
		cin >> s;
		n = s.length();
		res = 0;
		while (!st.empty()) st.pop();

		for (int i = 1; i <= n; i++){
			f[i] = 0;
			c = mp[s[i-1]];
			if (c > 0)
				st.push(make_pair(c, i));
			else{
				if (st.empty() || st.top().first + c)
					while (!st.empty()) st.pop();
				else{
					tmp = st.top();
					st.pop();
					f[i] = f[tmp.second - 1] + i - tmp.second + 1;
					res = max(res, f[i]);
				}
			}
		}
		cout << "Case #" << cs << "\n" << res << "\n";
	}

	return 0;
}