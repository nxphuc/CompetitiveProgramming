#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-6
const double PI = acos(-1.0);


double DEG_to_RAD(double d) {
	return d * PI / 180.0;
}

double RAD_to_DEG(double r) {
	return r * 180.0 / PI;
}

inline int cmp(double a, double b) {
	return a < b - EPS ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}

	Point operator+(Point a) { return Point(x + a.x, y + a.y); }
	Point operator-(Point a) { return Point(x - a.x, y - a.y); }
	Point operator*(double k) { return Point(x*k, y*k); }
	Point operator/(double k) { return Point(x/k, y/k); }
	double operator*(Point a) { return x*a.x + y*a.y; }
	double operator%(Point a) { return x*a.y - y*a.x; }
	int cmp(Point q) const {
		if (int t = ::cmp(x, q.x)) return t;
		return ::cmp(x, q.y);
	}

	#define Comp(x)bool operator x (Point q) const { return cmp(q) x 0; }
	Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
	#undef Comp

	Point conj() { return Point(x, -y); }
	double norm() { return x*x + y*y; }
	double len() { return sqrt(norm()); }
	Point rotate(double alpha) {
		double cosa = cos(alpha), sina = sin(alpha);
		return Point(x * cosa - y * sina, x * sina + y * cosa);
	}
};

double angle(Point a, Point o, Point b) {
	a = a - o;
	b = b - o;
	return acos((a*b) / sqrt(a.norm() * b.norm()));
}

struct Line {
	double a, b, c;
	Point A, B;

	Line(double a, double b, double c) : a(a), b(b), c(c) {}
	Line(Point A, Point B) : A(A), B(B) {
		a = B.y - A.y;
		b = A.x - B.x;
		c = - (a * A.x + b * A.y);
	}
};

bool areParallel(Line l1, Line l2) {
	return cmp(l1.a*l2.b, l1.b*l2.a) == 0;
}

bool areIntersect(Line l1, Line l2, Point &p) {
	if (areParallel(l1, l2)) {
		return false;
	}
	double dx = l1.b * l2.c - l2.b * l1.c;
	double dy = l1.c * l2.a - l2.c * l1.a;
	double d = l1.a * l2.b - l2.a * l1.b;
	p = Point(dx/d, dy/d);
	return true;
}

struct Circle : Point {
	double r;
	Circle(double x = 0, double y =0 , double r = 0) : Point(x, y), r(r) {}
	Circle(Point p, double r) : Point(p), r(r) {}
	bool contains(Point p) { return (*this - p).len() <= r + EPS; }
};

Point getcircumcircle(Point a, Point b, Point c) {
	double d = 2.0 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
	double x = (a.norm() * (b.y - c.y) + b.norm() * (c.y - a.y) + c.norm() * (a.y - b.y)) / d;
	double y = (a.norm() * (c.x - b.x) + b.norm() * (a.x - c.x) + c.norm() * (b.x - a.x)) / d;
	return Point(x, y);
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	Point p[3];
	for (int i = 0; i < 3; i++) {
		cin >> p[i].x >> p[i].y;
	}
	for (int i = 0; i < 3; i++) {
		double agl = angle(p[(i-1 + 3) % 3], p[i], p[(i + 1) % 3]);
		if (cmp(agl, DEG_to_RAD(120)) > 0) {
			cout << fixed << setprecision(9) << p[i].x << " " << p[i].y << "\n";
			return 0;
		}
	}
	// Point a1 = a.rotate(DEG_to_RAD(60));
	Point q[2];
	for (int i = 1; i < 3; i++) {
		Point tmp1 = (p[i] - p[i-1]).rotate(DEG_to_RAD(60.0)) + p[i-1];
		Point tmp2 = (p[i-1] - p[i]).rotate(DEG_to_RAD(60.0)) + p[i];
		if ((tmp1 - p[(3 - i - (i - 1))]).len() < (tmp2 - p[(3 - i - (i - 1))]).len()) {
			q[i-1] = tmp2;
		}
		else {
			q[i-1] = tmp1;
		}
	}

	// q[0] - p[2]
	// q[1] - p[0]
	Line l1(q[0], p[2]);
	Line l2(q[1], p[0]);
	Point res;
	areIntersect(l1, l2, res);
	cout << fixed << setprecision(9) << res.x << " " << res.y << "\n";

	return 0;
}
