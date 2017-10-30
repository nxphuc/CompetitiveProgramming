#include <bits/stdc++.h>
using namespace std;

int t;
pair<int,int> a[5];

int check(){
	sort(a,a+4);
	if (a[0].first != a[1].first || a[2].first != a[3].first)
		return 0;
	if (a[0].first == a[2].first) return 0;
	if (a[0].second != a[2].second || a[1].second != a[3].second)
		return 0;
	if (a[0].second == a[1].second)
		return 0;
	return 1;
}

int main(){
	cin >> t;
	while (t--){
		for (int i = 0; i < 4; i++)
			cin >> a[i].first >> a[i].second;
		cout << (check() ? "YES" : "NO") << "\n";
	}
}