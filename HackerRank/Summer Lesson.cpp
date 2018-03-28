#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int c[1010] = {0};
    int n, m, x;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        c[x]++;
    }
    for (int i = 0; i < m; i++) {
        cout << c[i] << " ";
    }

    return 0;
}