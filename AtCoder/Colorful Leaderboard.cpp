#include <bits/stdc++.h>
using namespace std;

int getType(int score){
	if (score < 400) return 0;
	if (score < 800) return 1;
	if (score < 1200) return 2;
	if (score < 1600) return 3;
	if (score < 2000) return 4;
	if (score < 2400) return 5;
	if (score < 2800) return 6;
	if (score < 3200) return 7;
	return 8;
}

int main(){
	int cnt[10] = {0};
	int n, x;

	cin >> n;
	while (n--){
		cin >> x;
		cnt[getType(x)]++;
	}
	n = 0;
	for (int i = 0; i < 8; i++)
		n += cnt[i] > 0;
	if (!n){
		cnt[8]--;
		n = 1;
	}
	cout << n << " " << n + cnt[8];
	return 0;
}