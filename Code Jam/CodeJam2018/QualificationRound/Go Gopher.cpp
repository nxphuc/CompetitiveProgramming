#include <bits/stdc++.h>
using namespace std;

pair<int, int> getSize(int a) {
    int r_min = a, c_min = a;
    for (int i = 3; i <= a; i++) {
        int j = a / i;
        if (i * j < a) {
            j++;
        }
        if (j < 3) {
            j = 3;
        }
        if (r_min*c_min > i * j) {
            r_min = i;
            c_min = j;
        }
    }
    return make_pair(r_min, c_min);
}

void doTestCase() {
    int a;
    cin >> a;

    pair<int, int> s = getSize(a);
    int x, y;
    set<pair<int, int>> list_cells;
    
    int c_x, c_y;
    for (int i = 1; i <= s.first; i++) {
        for (int j = 1; j <= s.second; j++) {
            c_x = i + 1;
            c_y = j + 1;
            while (c_x > s.first - 1) {
                c_x--;
            }
            while (c_y > s.second - 1) {
                c_y--;
            }
            cerr << "need " << i << " " << j << "\n";
            while (list_cells.find(make_pair(i, j)) == list_cells.end()) {
                cout << c_x << " " << c_y << "\n";
                cerr << "in " << c_x << " " << c_y << "\n";
                fflush(stdout);
                cin >> x >> y;
                cerr << "ou " << x << " " << y << "\n";
                if (x < 1 && y < 1) {
                    return;
                }
                // if (list_cells.find(make_pair(x, y)) != list_cells.end()) {
                list_cells.insert(make_pair(x, y));
                // }
            }
        }
    }
}

int main() {
    // freopen("test.in", "rt", stdin);
    // freopen("test.er", "wt", stderr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    cerr << t << "\n";
    while (t--) {
        doTestCase();
    }

    return 0;
}