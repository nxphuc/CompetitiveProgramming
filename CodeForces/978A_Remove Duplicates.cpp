#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    vector<int> a;
    cin >> n;
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            b.push_back(a[i]);
        }
    }
    cout << b.size() << "\n";
    for (int x: b) {
        cout << x << " ";
    }

    return 0;
}