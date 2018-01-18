#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-6
double DEG_to_RAD(double d) {
	return d * M_PI / 180.0;
}
double RAD_to_DEG(double r) {
	return r * 180.0 / M_PI;
}

inline int cmp(double a, double b) {
	return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point {
	double x, y;
	Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	Point operator + (Point a) { return Point(x+a.x, y+a.y); }
	Point operator - (Point a) { return Point(x-a.x, y-a.y); }
	Point operator * (double k) { return Point(x*k, y*k); }
	Point operator / (double k) { return Point(x/k, y/k); }
	double operator * (Point a) { return x*a.x + y*a.y; } // dot product
	double operator % (Point a) { return x*a.y - y*a.x; } // cross product
	int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }
	#define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
	Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
	#undef Comp
	Point conj() { return Point(x, -y); }
	double norm() { return x*x + y*y; }
	// Note: There are 2 ways for implementing len():
	// 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are of order X^2)
	// 2. hypot(x, y) --> slow, but much more accurate double len() { return sqrt(norm()); }
	double len() { return sqrt(norm()); }
	Point rotate(double alpha) { double cosa = cos(alpha), sina = sin(alpha);
		return Point(x * cosa - y * sina, x * sina + y * cosa);
	}
};

struct Circle : Point {
	double r;
	Circle(double x = 0, double y = 0, double r = 0) : Point(x, y), r(r) {}
	Circle(Point p, double r) : Point(p), r(r) {}
	bool contains(Point p) { return (*this - p).len() <= r + EPS; }
};

// Smallest enclosing circle:
// Given N points. Find the smallest circle enclosing these points.
// Amortized complexity: O(N)
struct SmallestEnclosingCircle {
	Circle getCircle(vector<Point> points) {
		assert(!points.empty()); random_shuffle(points.begin(), points.end());
		Circle c(points[0], 0); int n = points.size();
		for (int i = 1; i < n; i++)
			if ((points[i] - c).len() > c.r + EPS){
				c = Circle(points[i], 0);
				for (int j = 0; j < i; j++)
					if ((points[j] - c).len() > c.r + EPS) {
						c = Circle((points[i] + points[j]) / 2, (points[i] - points[j]).len() / 2);
						for (int k = 0; k < j; k++) if ((points[k] - c).len() > c.r + EPS) c = getCircumcircle(points[i], points[j], points[k]);
					}
			}
		return c;
	}
	Circle getCircumcircle(Point a, Point b, Point c) {
		double d = 2.0 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
		assert(fabs(d) > EPS);
		double x = (a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y) + c.norm() * (a.y - b.y)) / d;
		double y = (a.norm() * (c.x - b.x) + b.norm() * (a.x - c.x) + c.norm() * (b.x - a.x)) / d;
		Point p(x, y); return Circle(p, (p - a).len());
	}
};

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<Point> points(n);
	double res = -1;
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
	}
	SmallestEnclosingCircle sec;
	Circle c = sec.getCircle(points);
	cout << fixed << setprecision(6) << c.r;

	return 0;
}