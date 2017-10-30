#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1e5 + 10;
 
int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);
 
	int t, n, cnt, flag, tmp;
	string s[2];
 
	cin >> t;
	while (t--){
		cnt = 0;
 
		cin >> n;
		for (int i = 0; i < 2; i++){
			cin >> s[i];
			for (int j = 0; j < n; j++)
				cnt += s[i][j] == '*';
		}
 
		if (cnt <= 2)
			cout << max(0, cnt - 1) << "\n";
		else{
			cnt = 0;
			flag = -1;
			for (int i = 0; i < n; i++){
				tmp = (s[0][i] == '*') | ((s[1][i] == '*') << 1);
				if (!tmp)
					continue;
				if (tmp == 3){
					cnt++;
					cnt += flag != -1;
					flag = -1;
				}
				else{
					if (flag == -1)
						flag = tmp;
					else{
							cnt++;
							flag = tmp == flag ? tmp : -1;
						}
				}
			}
			// cout << cnt << " " << flag << "\n";
			cnt += (flag != -1);
			if (s[0] == string(n,'.') || s[1] == string(n, '.'))
				cout << cnt-1 << "\n";
			else
				cout << cnt << "\n";
		}
	}
 
	return 0;
}