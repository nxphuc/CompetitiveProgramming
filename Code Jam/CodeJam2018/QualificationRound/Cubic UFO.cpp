#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

void solveSmall(double s) {
    double lo = 0, hi = PI / 4;
    double mi;
    double edge;
    double edge_len = sqrt(2) / 2.0;

    for (int i = 0; i <= 100000; i++) {
        mi = (lo + hi) / 2;
        edge = edge_len * cos(mi);
        if (2 * edge > s) {
            lo = mi;
        }
        else {
            hi = mi;
        }
    }

    mi = (lo + hi) / 2;
    // cout << mi << "\n";
    double y = edge_len * cos(mi);
    double x = edge_len * sin(mi);
    pair<double, double> point_1, point_2, point_3;
    point_1 = make_pair(x, y);
    point_2 = make_pair(y, -x);
    point_3 = make_pair(-y, x);
    printf("%.20lf %.20lf 0\n", (point_1.first + point_2.first) / 2, (point_1.second + point_2.second) / 2);
    printf("%.20lf %.20lf 0\n", (point_1.first + point_3.first) / 2, (point_1.second + point_3.second) / 2);
    printf("0 0 0.5\n");
}

void doTestCase() {
    double s;
    scanf("%lf", &s);

    if (s <= sqrt(2)) {
        solveSmall(s);
    }
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        printf("Case #%d:\n", cs);
        doTestCase();
    }

    return 0;
}