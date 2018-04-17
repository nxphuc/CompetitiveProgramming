#include <bits/stdc++.h>
using namespace std;

void doTestCase() {
    int n, a, b;
    string s;
    cin >> a >> b;
    cin >> n;
    
    a += 1;
    while (true) {
        int m = (a + b) / 2;
        cout << m << "\n";
        fflush(stdout);
        cin >> s;
        if (s == "CORRECT") {
            return;
        }
        if (s == "TOO_BIG") {
            b = m - 1;
        }
        else {
            a = m + 1;
        }
    }
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        doTestCase();
    }

    return 0;
}