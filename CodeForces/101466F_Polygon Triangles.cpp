#include <bits/stdc++.h>
using namespace std;

int isTriangle(int a, int b, int c){
	return a+b > c && a+c > b && b+c > a;
}

int main(){
	int flag = 1;
	int n, a, b, c;

	cin >> n;
	while (n--){
		cin >> a >> b >> c;
		flag &= isTriangle(a, b, c);
	}
	cout << (flag ? "YES" : "NO");
	return 0;
}