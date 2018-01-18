#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-6;

int x[10], y[10];
int id[10];
int n;

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
};

struct Line {
	double a, b, c;
	Point A, B;
	Line(double a, double b, double c) : a(a), b(b), c(c) {}
	Line(Point A, Point B) : A(A), B(B) { a = B.y - A.y; b = A.x - B.x; c = - (a * A.x + b * A.y); }
	Line(Point P, double m) { a = -m; b = 1; c = -((a * P.x) + (b * P.y)); }
	double f(Point A) { return a*A.x + b*A.y + c; }
};

bool areParallel(Line l1, Line l2) {
	return cmp(l1.a*l2.b, l1.b*l2.a) == 0;
}
bool areSame(Line l1, Line l2) {
	return areParallel(l1 ,l2) && cmp(l1.c*l2.a, l2.c*l1.a) == 0;
}

double dist(Point p, Point q) {
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

double dist2(Point p, Point q) {
	return sqrt(dist(p, q));
}

int check() {
	Point p[7];
	for (int i = 0; i < 7; i++) {
		p[i] = Point(x[id[i]], y[id[i]]);
	}
	Line BC(p[0], p[3]);
	Line GF(p[1], p[2]);

	if (!areSame(BC, GF)) {
		return 0;
	}
	if (abs(dist2(p[0], p[1]) + dist2(p[1], p[2]) + dist2(p[2], p[3]) - dist2(p[0], p[3])) > EPS) {
		return 0;
	}
	if (dist(p[0], p[1]) != dist(p[2], p[3])) {
		return 0;
	}
	if (dist(p[1], p[2]) != dist(p[4], p[5])) { // GF vs DE
		return 0;
	}
	if (dist(p[1], p[4]) != dist(p[2], p[5])) {
		return 0;
	}
	if (dist(p[1], p[5]) != dist(p[2], p[4])) {
		return 0;
	}
	Point H((p[0].x + p[3].x) / 2, (p[0].y + p[3].y) / 2);
	Point I((p[1].x + p[5].x) / 2, (p[1].y + p[5].y) / 2);
	Line AH(p[6], H);
	Line AI(p[6], I);
	if (!areSame(AI, AH)) {
		return 0;
	}
	return abs(dist2(H, I)) + dist2(H, p[6]) - dist2(I, p[6]) <= EPS;
}

int main() {
	// freopen("input", "rt", stdin);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 7; i++) {
		cin >> x[i] >> y[i];
		id[i] = i;
		for (int j = 0; j < i; j++) {
			if (x[i] == x[j] && y[i] == y[j]) {
				cout << "No";
				return 0;
			}
		}
	}
	int cnt=  0;
	do {
		if (check()) {
			cout << "Yes";
			return 0;
		}
	} while (next_permutation(id, id + 7));
	cout << "No";

	return 0;
}