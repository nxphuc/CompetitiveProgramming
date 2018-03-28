#include <bits/stdc++.h>
using namespace std;

const double DOUBLE_MAX = 1e18;

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

bool xCompare(const Point& lft, const Point& rht) {
    return lft.x < rht.x;
}

bool yCompare(const Point& lft, const Point& rht) {
    return lft.y < rht.y;
}

double distance(Point &a, Point &b) {
    double x = a.x - b.x;
    double y = a.y - b.y;
    return sqrt(x * x + y * y);
}

double bruteForce(vector<Point> &points, int left, int right) {
    double min_dist = DOUBLE_MAX;
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            min_dist = min(min_dist, distance(points[i], points[j]));
        }
    }
    return min_dist;
}

double stripClosest(vector<Point> &points, int left, int right, int mid, double dist) {
    Point point_mid = points[mid];

    vector<Point> splitted_points;
    // splitted_points.reserve(right - left);
    for (int i = left; i < right; ++i) {
        if (abs(points[i].x - point_mid.x) <= dist) {
            splitted_points.push_back(points[i]);
        }
    }

    sort(splitted_points.begin(), splitted_points.end(), yCompare);

    double min_dist = DOUBLE_MAX;
    int l = splitted_points.size();
    for (int i = 0; i < l; ++i) {
        // for (int j = i + 1; j < l && splitted_points[j].y - splitted_points[i].y < dist; ++j) {
            min_dist = min(min_dist, distance(splitted_points[i], splitted_points[j]));
        }
    }

    return min_dist;
}

double closestUtil(vector<Point> &points, int left, int right) {
    if (right - left <= 3) {
        return bruteForce(points, left, right);
    }

    int mid = (right + left) / 2;
    double dist_left = closestUtil(points, left, mid);
    double dist_right = closestUtil(points, mid + 1, right);
    double dist = min(dist_left, dist_right);
    return min(dist, stripClosest(points, left, right, mid, dist));
}

int main() {
    ios::sync_with_stdio(false);

    unsigned int n;
    double x, y;
    int idx = 0;
    cin >> n;
    vector<Point> points;
    // points.reserve(n);
    while (n--) {
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    
    sort(points.begin(), points.end(), xCompare);
    double ans = closestUtil(points, 0, points.size());
    
    cout << fixed << setprecision(3) << ans;
    return 0;
}