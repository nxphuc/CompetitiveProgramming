#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-9;

vector<double> y;
vector<double> x;
int n, r;

double calc(double x, double y, double xx) {
	double a = fabs(xx - x);
	double c = 2*r;
	if (c >= a) {
		return sqrt(c*c - a*a) + y;
	}
	return r;
}

double find(double xx) {
	double res = r;
	for (int i = 0; i < y.size(); i++) {
		res = max(res, calc(x[i], y[i], xx));
	}
	return res;
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	double coor;

	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> coor;
		x.push_back(coor);
		if (i == 0) {
			y.push_back(r);
		}
		else {
			y.push_back(find(coor));
		}
	}
	for (auto yy : y) {
		cout << fixed << setprecision(12) << yy << " ";
	}
	
	return 0;
}