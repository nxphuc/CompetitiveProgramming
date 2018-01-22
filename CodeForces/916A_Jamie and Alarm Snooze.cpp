#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    long long x, h, m;
    cin >> x >> h >> m;
    for (long long i = 0; ; i++) {
        long long t = h * 60 + m - x * i;
        while (t < 0) {
            t += 24*60;
        }
        if ((t % 60) % 10 == 7 || (t / 60) % 10 == 7) {
            cout << i;
            return 0;
        }
    }

    return 0;
}