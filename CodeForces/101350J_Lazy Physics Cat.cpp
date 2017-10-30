#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

int main(){
	ios::sync_with_stdio(false);

	int t, l, a;
	double areaTri, areaCir;

	cin >> t;
	while (t--){
		cin >> l >> a;
		areaTri = l*l*sin(1.0*a*PI/180)/2;
		areaCir = PI*l*l*(1.0*a/360);
		cout << fixed << setprecision(6) << areaCir - areaTri << "\n";
	}

	return 0;
}