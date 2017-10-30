/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 1e6 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e6;
const double pi = acos(-1.0);
const double eps = 1e-6;

double DEG_to_RAD(double d) { return d * pi / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / pi; }

inline int cmp(double a, double b) {
	return (a < b - eps) ? -1 : ((a > b + eps) ? 1 : 0);
}

struct Point {
	double x, y;
	Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

	Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
	Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
	Point operator * (double k) const { return Point(x*k, y*k); }
	Point operator / (double k) const { return Point(x/k, y/k); }

	double operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product
	double operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product

	int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }

	#define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
	Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
	#undef Comp

	Point conj() { return Point(x, -y); }
	double norm() { return x*x + y*y; }

	// Note: There are 2 ways for implementing len():
	// 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are of order X^2)
	// 2. hypot(x, y) --> slow, but much more accurate
	double len() { return sqrt(norm()); }

	Point rotate(double alpha) {
		double cosa = cos(alpha), sina = sin(alpha);
		return Point(x * cosa - y * sina, x * sina + y * cosa);
	}
};

int ccw(Point a, Point b, Point c) {
	return cmp((b-a)%(c-a),0);
}
int RE_TRAI = ccw(Point(0, 0), Point(0, 1), Point(-1, 1));
int RE_PHAI = ccw(Point(0, 0), Point(0, 1), Point(1, 1));
istream& operator >> (istream& cin, Point& p) {
	cin >> p.x >> p.y;
	return cin;
}
ostream& operator << (ostream& cout, Point& p) {
	cout << p.x << ' ' << p.y;
	return cout;
}

// NOTE: WILL NOT WORK WHEN a = b = 0.
struct Line {
	double a, b, c;
	Point A, B; // Added for polygon intersect line. Do not rely on assumption that these are valid

	Line(double a, double b, double c) : a(a), b(b), c(c) {} 

	Line(Point A, Point B) : A(A), B(B) {
		a = B.y - A.y;
		b = A.x - B.x;
		c = - (a * A.x + b * A.y);
	}
	Line(Point P, double m) {
		a = -m; b = 1;
		c = -((a * P.x) + (b * P.y));
	}
	double f(Point A) {
		return a*A.x + b*A.y + c;
	}
};

bool areParallel(Line l1, Line l2) {
	return cmp(l1.a*l2.b, l1.b*l2.a) == 0;
}

bool areSame(Line l1, Line l2) {
	return areParallel(l1 ,l2) && cmp(l1.c*l2.a, l2.c*l1.a) == 0
				&& cmp(l1.c*l2.b, l1.b*l2.c) == 0;
}

bool areIntersect(Line l1, Line l2, Point &p) {
	if (areParallel(l1, l2)) return false;
	double dx = l1.b*l2.c - l2.b*l1.c;
	double dy = l1.c*l2.a - l2.c*l1.a;
	double d  = l1.a*l2.b - l2.a*l1.b;
	p = Point(dx/d, dy/d);
	return true;
}

double distToPoint(Point p, Point q){
	return Point(p - q).len();
	return sqrt((p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y));
}

double distToLine(Point p, Point a, Point b, Point &c) {
    Point ap = p - a, ab = b - a;
    double u = (ap * ab) / ab.norm();
    c = a + (ab * u);
    return (p-c).len();
}

int solve(Point p[], Point q[]){
	{
		sort(p, p+4);
		int n = unique(p, p + 4) - p;
		if (n == 1){
			q[0] = p[0];
			q[1] = Point(-101, -101);
			q[2] = Point(101, 101);
			return 1;
		}
		if (n == 2){
			q[0] = p[0];
			q[1] = p[1];
			q[2] = Point(101, 101);
			return 1;
		}
		if (n == 3){
			for (int i = 0; i < 3; i++)
				q[i] = p[i];
			return 1;
		}
	}

	{
		// Line l1(p[0], p[1]);
		// Line l2(p[2], p[3]);
		if (distToLine(p[2], p[0], p[1], q[0]) < eps && distToLine(p[3], p[0], p[1], q[0]) < eps){
			sort(p, p+4);
			q[0] = p[0];
			q[1] = p[3];
			q[2] = Point(101, 101);
			return 1;
		}
	}

	{
		for (int i = 0; i < 4; i++){
			swap(p[i], p[0]);
			// Line l1(p[1], p[2]);
			// Line l2(p[2], p[3]);
			if (distToLine(p[1], p[2], p[3], q[0]) < eps){
				sort(p+1, p+4);
				q[0] = p[0];
				q[1] = p[1];
				q[2] = p[3];
				return 1;
			}
			swap(p[i], p[0]);
		}
	}

	{
		Point pp;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (i != j){
					for (int k = 0; k < 4; k++)
						if (k != i && k != j){
							int h = 6 - i - j - k;
							Line l1(p[i], p[j]);
							Line l2(p[k], p[h]);
							if (areIntersect(l1, l2, pp)) {
								if (fabs(distToPoint(p[i], pp) + distToPoint(pp, p[j]) - distToPoint(p[i], p[j])) < eps
									&& (distToPoint(p[k], pp) + distToPoint(pp, p[h]) - distToPoint(p[k], p[h])) < eps)
									continue;
								if (fabs(distToPoint(p[i], pp) + distToPoint(pp, p[j]) - distToPoint(p[i], p[j])) < eps){
									q[0] = distToPoint(p[k], pp) > distToPoint(pp, p[h]) ? p[k] : p[h];
									q[1] = p[i];
									q[2] = p[j];
									return 1;
								}
								if (fabs(distToPoint(p[k], pp) + distToPoint(pp, p[h]) - distToPoint(p[k], p[h])) < eps){
									q[0] = distToPoint(p[i], pp) > distToPoint(pp, p[j]) ? p[i] : p[j];
									q[1] = p[k];
									q[2] = p[h];
									return 1;
								}
								q[0] = pp;
								q[1] = distToPoint(p[i], pp) < distToPoint(p[j], pp) ? p[j] : p[i];
								q[2] = distToPoint(p[k], pp) < distToPoint(p[h], pp) ? p[h] : p[k];
									return 1;
							}
						}
				}
	}
	return 0;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	Point p[4], q[3];
	int t;

	cin >> t;
	while (t--){
		REP(i,0,4)
			cin >> p[i].x >> p[i].y;
		if (solve(p, q)){
			cout << "YES";
			REP(i,0,3)
				cout << fixed << setprecision(10) << " " << q[i].x << " " << q[i].y;
			cout << "\n";
		}
		else
			cout << "NO\n";
	}

	return 0;
}