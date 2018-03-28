#include <bits/stdc++.h>
using namespace std;

const int MAX = 510;

struct Package {
    int length, num_copies;

    Package(int length = 0, int num_copies = 0) 
        : length(length), num_copies(num_copies) {}

    bool operator < (const Package& other) const {
        return length > other.length;
    }
};

struct Cylinder {
    int radius, capacity;

    Cylinder(int radius = 0, int capacity = 0)
        : radius(radius), capacity(capacity) {}
    
    bool operator < (const Cylinder& other) const {
        return radius > other.radius;
    }
};

vector<Package> packages;
vector<Cylinder> cylinders;
int n, m;

int canPut(int cubeLength, int radius) {
    return 2 * cubeLength * cubeLength <= radius * radius;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    packages.resize(n);
    cylinders.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> packages[i].length;
    }
    for (int i = 0; i < n; i++) {
        cin >> packages[i].num_copies;
    }
    for (int i = 0; i < m; i++) {
        cin >> cylinders[i].radius;
    }
    for (int i = 0; i < m; i++) {
        cin >> cylinders[i].capacity;
    }
    sort(packages.begin(), packages.end());
    sort(cylinders.begin(), cylinders.end());
    int res = 0, j = 0;
    for (int i = 0; i < m; i++) {
        while (cylinders[i].capacity > 0 && j < n) {
            if (canPut(packages[j].length, 2 * cylinders[i].radius)) {
                int num = min(packages[j].num_copies, cylinders[i].capacity);
                res += num;
                cylinders[i].capacity -= num;
                packages[j].num_copies -= num;
                if (packages[j].num_copies == 0) {
                    j++;
                }
            }
            else {
                j++;
            }
        }
    }
    cout << res;

    return 0;
}