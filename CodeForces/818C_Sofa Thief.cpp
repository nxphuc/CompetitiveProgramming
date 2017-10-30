#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int a[MAX][4];
int cntLeft[MAX], cntRight[MAX], cntTop[MAX], cntBot[MAX];
int num[4];
int d, n, m, cnt;
int l, r, t, b;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> d >> n >> m;
	for (int i = 1; i <= d; i++){
		for (int j = 0; j < 4; j++)
			cin >> a[i][j];
		cntLeft[min(a[i][0], a[i][2])]++;
		cntRight[max(a[i][0], a[i][2])]++;
		cntTop[min(a[i][1], a[i][3])]++;
		cntBot[max(a[i][1], a[i][3])]++;
	}
	for (int i = 0; i < 4; i++)
		cin >> num[i];
	cnt = 0;
	for (int i = 0; i <= n; i++){
		cnt += cntLeft[i];
		if (cnt > num[0]){
			cout << -1;
			return 0;
		}
		if (cnt == num[0]){
			l = i;
			break;
		}
	}
	cnt = 0;
	for (int i = n+1; i > 0; i--){
		cnt += cntRight[i];
		if (cnt > num[1]){
			cout << -1;
			return 0;
		}
		if (cnt == num[1]){
			r = i;
			break;
		}
	}
	cnt = 0;
	for (int i = 0; i <= m; i++){
		cnt += cntTop[i];
		if (cnt > num[2]){
			cout << -1;
			return 0;
		}
		if (cnt == num[2]){
			l = i;
			break;
		}
	}
	cnt = 0;
	for (int i = m+1; i > 0; i--){
		cnt += cntBot[i];
		if (cnt > num[3]){
			cout << "##" << i << " " << cnt << " ";
			cout << -1;
			return 0;
		}
		if (cnt == num[3]){
			l = i;
			break;
		}
	}
	cout << l << " " << r << " " << t << " " << b << "\n";
	for (int i = 1; i <= d; i++){
		if (	l < min(a[i][0], a[i][2])
		 	&&  r > max(a[i][0], a[i][2])
		 	&&  t < min(a[i][1], a[i][3])
		 	&&  b > max(a[i][1], a[i][3])){
		 	cout << i;
		 	return 0;
		 }
	}
	cout << -1;

	return 0;
}