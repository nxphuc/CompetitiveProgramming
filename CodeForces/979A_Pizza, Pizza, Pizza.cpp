#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;
    n += 1;
    if (n == 1) {
        cout << 0;
    }
    else {
        cout << ((n & 1) ? n : n / 2) << "\n";
    }

    return 0;
}