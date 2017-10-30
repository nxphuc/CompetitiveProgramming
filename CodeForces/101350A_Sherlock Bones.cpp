#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX = 2e5 + 10;

string s;
int t, n;
vector<ll> f, g;
int cnt;
ll res;

int main(){
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--){
		cin >> n >> s;

		s = " " + s;
		f.clear(); g.clear();
		res = 0;
		cnt = 0;
		
		for (int i = 1; i <= n; i++){
			cnt++;
			if (s[i] == '1'){
				f.push_back(cnt);
				cnt = 0;
			}
		}
		
		cnt = 0;
		for (int i = n; i > 0; i--){
			cnt++;
			if (s[i] == '1'){
				g.push_back(cnt);
				cnt = 0;
			}
		}
		reverse(g.begin(), g.end());

		for (int i = 0; i < f.size(); i++){
			res -= f[i] + g[i] - 1;
		}

		for (int i = 2; i < f.size(); i++)
			f[i] += f[i-2];
		for (int i = 0; i < g.size(); i++)
			res += f[i]*g[i];

		cout << res << "\n";
	}

	return 0;
}