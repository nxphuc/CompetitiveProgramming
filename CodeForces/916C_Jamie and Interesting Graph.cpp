#include <bits/stdc++.h>
using namespace std;

int isPrime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int tot = n - 1;
    while (!isPrime(tot)) {
        ++tot;
    }
    cout << tot << " " << tot << "\n";
    cout << "1 2 " << tot - n + 2 << "\n";
    for (int i = 2; i < n; i++) {
        cout << i << " " << i + 1 << " 1\n";
    }
    m -= n - 1;
    for (int i = 1; m && i < n; i++) {
        for (int j = i + 2; m && j < n; j++) {
            cout << i << " " << j << " 1000000000" << "\n";
            m--;
        }
    }

    return 0;
}