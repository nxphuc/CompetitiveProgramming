#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    long long n, k, x;

    cin >> n >> k;
    long long m = min(k, 10000000LL);
    vector<bool> mark(1000000, false);
    for (int i = 1; i <= m; i++) {
        x = n % i;
        if (mark[x]) {
            cout << "No";
            return 0;
        }
        mark[x] = true;
    }
    cout << "Yes";

    return 0;
}