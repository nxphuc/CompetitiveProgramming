#include <bits/stdc++.h> 

using namespace std; 

const double EPS = 0.0000001;

int test, a, b;

double cal(double x)
{
	return (1.0 * a - 2 * x) * (1.0 * b - 2 * x) * x;
}

int main () { 
	// freopen("text.in", "r", stdin);
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d", &a, &b);
		double lo = 0;
		double hi = min(a, b) / 2.0;
		while (hi - lo > EPS) {
			double m = (hi - lo) / 3;
			double left = lo + m;
			double right = lo + 2 * m;
			if (cal(left) > cal(right)) {
				hi = right;
			} else {
				lo = left;
			}
		}
		printf("%.10f\n", cal(lo));
	}
	
	return 0;
}