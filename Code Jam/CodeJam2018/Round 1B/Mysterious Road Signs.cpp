#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

map<pair<int, pair<int, int>>, int> my_map;
vector<int> a, b;
vector<int> next_a, next_b;
int n;

int getLength(int pos, int x, int y) {
    if (pos >= n) {
        return 0;
    }

    if (a[pos] != x && b[pos] != y) {
        return 0;
    }

    auto key = make_pair(pos, make_pair(x, y));
    if (my_map.find(key) != my_map.end()) {
        return my_map[key];
    }

    int length_a = 0;
    if (a[pos] == x) {
        int next_pos = next_a[pos];
        if (next_pos >= n) {
            length_a = n - pos;
        }
        else {
            length_a = next_pos - pos + (b[next_pos] == y ? getLength(next_pos, x, y) : 0);
        }
    }

    int length_b = 0;
    if (b[pos] == y) {
        int next_pos = next_b[pos];
        if (next_pos >= n) {
            length_b = n - pos;
        }
        else {
            length_b = next_pos - pos + (a[next_pos] == x ? getLength(next_pos, x, y) : 0);
        }
    }
    // cerr << "# " << pos << " " << x << " " << y << " " << length_a << " " << length_b << "\n";
    return my_map[key] = max(length_a, length_b);
}

// void printVector(const vector<int>& v) {
//     for (int x: v) {
//         cerr << x << " ";
//     }
//     cerr << "\n";
// }

void doTestCase() {
    my_map.clear();
    a.clear();
    b.clear();
    next_a.clear();
    next_b.clear();
    
    cin >> n;
    for (int x, y, z, i = 0; i < n; i++) {
        cin >> x >> y >> z;
        a.push_back(x + y);
        b.push_back(x - z);
    }

    // find next of a
    {
        int cur = 0;
        next_a.assign(n, n);
        for (int i = 0; i < n; i++) {
            if (a[i] != a[cur]) {
                while (cur != i) {
                    next_a[cur++] = i;
                }
            }
        }
    }

    // find next of b
    {
        int cur = 0;
        next_b.assign(n, n);
        for (int i = 0; i < n; i++) {
            if (b[i] != b[cur]) {
                while (cur != i) {
                    next_b[cur++] = i;
                }
            }
        }
    }

    // printVector(a);
    // printVector(b);
    // printVector(next_a);
    // printVector(next_b);

    int max_res = 0, cnt_res = 0;
    for (int length, x, y, next_pos, i = 0; i < n; i++) {
        length = 0;

        // fixed a
        {
            x = a[i];
            next_pos = next_a[i];
            y = next_pos < n ? b[next_pos] : INF;
            length = max(length, getLength(i, x, y));
        }

        // fixed b
        {
            y = b[i];
            next_pos = next_b[i];
            x = next_pos < n ? a[next_pos] : INF;
            length = max(length, getLength(i, x, y));
        }

        if (length == max_res) {
            cnt_res++;
        }
        else if (length > max_res) {
            max_res = length;
            cnt_res = 1;
        }
    }

    cout << max_res << " " << cnt_res << "\n";
}

int main() {
    // freopen("test.in", "rt", stdin);
    // freopen("test.er", "wt", stderr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        doTestCase();
    }

    return 0;
}