// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     // freopen("test.in", "rt", stdin);
//     ios::sync_with_stdio(false);

//     int n, m;
//     int res = -1, flag = -1;
//     string s;

//     cin >> n;
//     for (int i = 0; i < 3; i++) {
//         int cnt[100] = {0};
//         int max_cnt = -1;

//         cin >> s;
//         m = s.length();
//         for (char ch : s) {
//             int id = (ch >= 'a') ? (ch - 'a' + 26) : (ch - 'A');
//             cnt[id]++;
//             max_cnt = max(max_cnt, cnt[id]);
//         }
//         if (m >= n + max_cnt) {
//             max_cnt += n;
//         }
//         else {
//             int tmp = n - m + max_cnt;
//             // cerr << tmp << " " << m << "\n";
//             if ((tmp % m == 0) || (tmp % 2 == 0) || (tmp >= m && (tmp - m) % 2 == 0)) {
//                 max_cnt = m;
//             }
//             else {
//                 max_cnt = m - 1;
//             }
//         }

//         if (res == max_cnt) {
//             flag = -1;
//         }
//         else if (res < max_cnt) {
//             res = max_cnt;
//             flag = i;
//         }
//         // cout << max_cnt[i] << " ";
//     }
//     // cout << "\n";
//     if (flag == -1) {
//         cout << "Draw";
//     }
//     else {
//         string name[3] = {"Kuro", "Shiro", "Katie"};
//         cout << name[flag];
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);
 
    int n, m;
    int res = -1, flag = -1;
    string s;
 
    cin >> n;
    for (int i = 0; i < 3; i++) {
        int cnt[100] = {0};
        int max_cnt = -1;
 
        cin >> s;
        m = s.length();
        for (char ch : s) {
            int id = (ch >= 'a') ? (ch - 'a' + 26) : (ch - 'A');
            cnt[id]++;
            max_cnt = max(max_cnt, cnt[id]);
        }
        if (m >= n + max_cnt) {
            max_cnt += n;
        }
        else {
            if (max_cnt == m) {
                if (n == 1) max_cnt = max(1, m-1);
                else max_cnt = m;
            }
            else {
                max_cnt = m;
            }
        }
 
        if (res == max_cnt) {
            flag = -1;
        }
        else if (res < max_cnt) {
            res = max_cnt;
            flag = i;
        }
        // cout << max_cnt[i] << " ";
    }
    // cout << "\n";
    if (flag == -1) {
        cout << "Draw";
    }
    else {
        string name[3] = {"Kuro", "Shiro", "Katie"};
        cout << name[flag];
    }
 
    return 0;
}