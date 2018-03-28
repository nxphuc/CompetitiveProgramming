// #include <bits/stdc++.h>
// using namespace std;

// const int MAX = 1e5 + 10;
// typedef long long ll;

// int a[MAX];

// int main() {
//     freopen("test.in", "rt", stdin);
//     ios::sync_with_stdio(false);

//     cin >> n;
//     for (int i = 1; i < n; i++) {
//         cin >> a[i];
//     }
//     sort(a, a+n);
//     for (int val = a[n-1]; ; val--) {
//         ll tmp, cnt = 0;
//         int i;
//         for (i = n-1; i >= 0 && a[i] >= val; i--) {
//             tmp = a[i] - val;
//             cnt += 1LL << tmp;
//         }
//         if (cnt < i) {
//             continue;
//         }
        
//     }

//     return 0;
// }