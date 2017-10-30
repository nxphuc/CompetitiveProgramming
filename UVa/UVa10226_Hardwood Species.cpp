#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

set< pair<string,int> > myset;
set< pair<string,int> >::iterator it;
int t, cnt, flag;
char s[100];

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	// ios::sync_with_stdio(false);

	scanf("%d", &t);
	gets(s);
	gets(s);
	while (t--){
		myset.clear();
		cnt = 0;
		do{
			if (!gets(s))
				break;
			if (strlen(s) < 1)
				break;
			
			cnt++;
			it = myset.lower_bound(make_pair(s, 0));
			if (it == myset.end() || it->first != s)
				myset.insert(make_pair(s, 1));
			else{
				int number = (it->second) + 1;
				myset.erase(it);
				myset.insert(make_pair(s, number));
			}
		} while (1);
		flag = 1;
		for (it = myset.begin(); it != myset.end(); it++)
			printf("%s %.4lf\n", (it->first).c_str(), 100.0*(it->second) / cnt);
		if (t) printf("\n");
	}

	return 0;
}