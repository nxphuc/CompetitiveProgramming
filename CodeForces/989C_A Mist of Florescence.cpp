// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     freopen("test.in", "rt", stdin);
//     ios::sync_with_stdio(false);

//     pair<int, char> a[4];
//     for (int i = 0; i < 4; i++) {
//         cin >> a[i].first;
//         a[i].second = 'A' + i;
//     }
//     sort(a.begin(), a.end(), greater<pair<int, char>>());
//     int n, m = (a[0].first - 1) / 2 + 1;
//     m += m & 1;
//     m = min(m, 50);
//     vector<string> f;
//     for (int row_id = 0; ; row_id++) {
//         f.push_back(string(m, '.'));
//         int i = (row_id == 0 || (f[row_id - 1][0] != a[0].second)) ? 0 : 1;

//     }

//     return 0;
// }