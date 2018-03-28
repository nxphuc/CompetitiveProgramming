#include <bits/stdc++.h>
using namespace std;

int existsZero(int n) {
    while (n) {
        if (n % 10 == 0) {
            return 1;
        }
        n /= 10;
    }
    return 0;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    do {
        ++n;
    } while (existsZero(n));
    cout << n;

    return 0;
}