struct Circle : Point {
	double r;
	Circle(double x = 0, double y = 0, double r = 0) : Point(x, y), r(r) {}
	Circle(Point p, double r) : Point(p), r(r) {}
	bool contains(Point p) { return (*this - p).len() <= r + EPS; }
};

// Find common tangents to 2 circles
// Helper method
void tangents( Point c, double r1, double r2, vector<Line> & ans) {
	double r = r2 - r1;
	double z = sqr(c.x) + sqr(c.y);
	double d = z - sqr(r);
	if (d < -EPS) return;
	d = sqrt(fabs(d));
	Line l((c.x * r + c.y * d) / z, (c.y * r - c.x * d) / z, r1);
	ans.push_back(l);
}

// Actual method: returns vector containing all common tangents
vector<Line> tangents(Circle a, Circle b) {
	vector<Line> ans; ans.clear();
	for (int i=-1; i<=1; i+=2)
		for (int j=-1; j<=1; j+=2)
			tangents(b-a, a.r*i, b.r*j, ans);
	for(int i = 0; i < ans.size(); ++i)
		ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
	vector<Line> ret;
	for(int i = 0; i < (int) ans.size(); ++i) {
		bool ok = true;
		for(int j = 0; j < i; ++j)
			if (areSame(ret[j], ans[i])) {
				ok = false; break;
			}
			if (ok) ret.push_back(ans[i]);
	}
	return ret;
}

// Circle & line intersection
vector<Point> intersection(Line l, Circle cir) {
	double r = cir.r, a = l.a, b = l.b, 
			c = l.c + l.a*cir.x + l.b*cir.y;
	vector<Point> res;
	double x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);
	if (c*c > r*r*(a*a+b*b)+EPS) return res;
	else
		if (fabs(c*c - r*r*(a*a+b*b)) < EPS) {
			res.push_back(Point(x0, y0) + Point(cir.x, cir.y));
			return res;
		}
		else {
			double d = r*r - c*c/(a*a+b*b);
			double mult = sqrt (d / (a*a+b*b));
			double ax,ay,bx,by;
			ax = x0 + b * mult;
			bx = x0 - b * mult;
			ay = y0 - a * mult;
			by = y0 + a * mult;
			res.push_back(Point(ax, ay) + Point(cir.x, cir.y));
			res.push_back(Point(bx, by) + Point(cir.x, cir.y));
			return res;
		}
}

//return the common area of two circle
double commonCircleArea(Circle c1, Circle c2) {
	double d = hypot(c1.x-c2.x, c1.y-c2.y), area;
	if (c1.r+c2.r <= d) area = 0;
	else
		if (c2.r+d <= c1.r)
			area = (c1.r * c1.r - c2.r * c2.r) * M_PI;
		else
			if (c1.r+d <= c2.r)
				area = (c2.r * c2.r - c1.r * c1.r) * M_PI;
			else {
				double p1 = c2.r * c2.r * acos((d*d + c2.r*c2.r - c1.r*c1.r) / (2*d*c2.r));
				double p2 = c1.r * c1.r * acos((d*d + c1.r*c1.r - c2.r*c2.r) / (2*d*c1.r));
				double p3 = 0.5 * sqrt((-d+c2.r+c1.r) * (d+c2.r-c1.r) * (d+c1.r-c2.r) * (d+c1.r+c2.r));
				area = p1 + p2 - p3;
			}
	return area;
}

// Smallest enclosing circle:
// Given N points. Find the smallest circle enclosing these points.
// Amortized complexity: O(N)
struct SmallestEnclosingCircle {
	Circle getCircle(vector<Point> points) {
		assert(!points.empty());
		random_shuffle(points.begin(), points.end());
		Circle c(points[0], 0);
		int n = points.size();
		for (int i = 1; i < n; i++)
			if ((points[i] - c).len() > c.r + EPS){
				c = Circle(points[i], 0);
				for (int j = 0; j < i; j++)
					if ((points[j] - c).len() > c.r + EPS) {
						c = Circle((points[i] + points[j]) / 2,
									(points[i] - points[j]).len() / 2);
						for (int k = 0; k < j; k++)
							if ((points[k] - c).len() > c.r + EPS)
								c = getCircumcircle(points[i], points[j], points[k]);
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
