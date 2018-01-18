#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
	int t;
	ll s, x, y;
	
	cin >> t;
	for (int cs = 1; cs <= t; cs++){
		cin >> s;
		x = sqrt(s);
		if (x * x < s){
			x++;
		}
		y = x;
		s -= (x-1)*(x-1);
		if (x & 1){
			if (s > x)
			    x = 2*x - s;
			else
				y = s;
		}
		else{
			if (s > x)
				y = 2*x - s;
			else
				x = s;
		}
		cout << "Case " << cs << ": " << x << " " << y << "\n";

	}

	return 0;
}