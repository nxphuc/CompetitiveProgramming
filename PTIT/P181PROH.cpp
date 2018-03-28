#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    long long a, b, res = 0;
    cin >> a >> b;
    if (a == b) {
        cout << "infinity";
        return 0;
    }
    a -= b;
    for (long long i = 1; i*i <= a; i++) {
        if (a % i == 0) {
            if (i > b) {
                res++;
            }
            if (a/i > b && i*i < a) {
                res++;
            }
        }
    }
    cout << res;

    return 0;
}