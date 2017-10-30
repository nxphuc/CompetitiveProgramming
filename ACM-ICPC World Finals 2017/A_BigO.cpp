#include <bits/stdc++.h>
using namespace std;

const int MAX = 210;
const double INF = 1e9;
const double EPS = 1e-9;

struct Point{
	double x, y;

	Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	Point(const Point& p) { x = p.x; y = p.y; }

	double operator*(const Point& p) const { return x*p.x + y*p.y; }
	double operator%(const Point& p) const { return x*p.y - y*p.x; }
	Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
	Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
	Point operator*(double c) const { return Point(x*c, y*c); }
	Point operator/(double c) const { return Point(x/c, y/c); }

	double norm() { return x*x + y*y; }
	double len(){ return sqrt(norm()); }
};

int n;
Point a[MAX];
double res;

bool areIntersect(Point a, Point b, Point c, Point d, Point &p){
	double x = (c - a) % (b - a);
	double y = (d - a) % (b - a);
	if (x*y > EPS)
		return false;
	if (fabs(x - y) < EPS)
		return false;
	p = c + (d - c) * (x / (x - y));
	return true;
}

struct PCompare{
	Point a, b;

	PCompare(Point a, Point b) : a(a), b(b) {}
	bool operator()(const Point& p, const Point& q){
		return (p - a)*(b - a) < (q - a)*(b - a);
		// if (fabs(p.x - q.x) < EPS)
		// 	return p.y < q.y;
		// return p.x < q.x;
	}
};

bool inPolygon(const Point& p){
	for (int i = 0; i < n; i++){
		if (fabs((p - a[i]) % (a[i+1] - a[i])) > EPS) continue;
		if ((p - a[i])*(a[i+1] - a[i]) < -EPS) continue;
		if ((p - a[i+1])*(a[i] - a[i+1]) < -EPS) continue;
		return true;
	}

	int flag = 0;
	for (int i = 0; i < n; i++){
		Point u = a[i], v = a[i+1];
		if (fabs(u.x - v.x) < EPS) continue;
		if (u.x > v.x) swap(u, v);
		if (p.x < u.x - EPS) continue;
		if (p.x > v.x - EPS) continue;
		if ((p - u) % (v - u) > 0)
			flag ^= 1;
	}
	return flag;
}

int main(){
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
	a[n] = a[0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++){
			vector<Point> v;
			Point tmp, p = a[i], q = a[j];

			// v.push_back(p + (p - q)*INF);
			// v.push_back(p - (p - q)*INF);
			for (int k = 0; k < n; k++)
				if (areIntersect(p, q, a[k], a[k+1], tmp))
					v.push_back(tmp);
			sort(v.begin(), v.end(), PCompare(p, q));
			// sort(v.begin(), v.end());

			Point prev = v[0];
			for (int k = 0; k+1 < v.size(); k++){
				if (!inPolygon((v[k] + v[k+1])*0.5))
					prev = v[k+1];
				res = max(res, (v[k+1] - prev).len());
			}
		}
	cout << fixed << setprecision(10) << res;
	return 0;
}
