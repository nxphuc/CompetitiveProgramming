#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    string s;
    int n;

    cin >> n >> s;

    int cnt = 0;
    int cont = 0;
    for (char ch : s) {
        if (ch == 'x') {
            cont++;
        }
        else {
            cnt += max(0, cont - 2);
            cont = 0;
        }
    }
    cnt += max(0, cont - 2);
    cout << cnt;

    return 0;
}