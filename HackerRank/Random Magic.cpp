// f[num][k][q][mask][last]
// num: số là bái đã dùng
// k: số K đã dùng
// q: số Q đã dùng
// mask: trạng thái đã tạo thành (0: chưa, 1: có K, 2: có Q, 3: có cả 2)
// last: lá bài cuối cùng
// 48*48*48*MAX_S*4

#include <bits/stdc++.h>
using namespace std;

const int MAX_S = 36;
const int MAX_C = 48;
const int MAX = MAX_S*MAX_C;

double f[MAX + 2][MAX_S + 1][MAX_S + 1][4][3];

void prepare() {
    f[0][0][0][0][0] = 1;
    f[1][0][0][0][0] = 1;
    f[1][1][0][0][1] = 1;
    f[1][0][1][0][2] = 1;

    for (int num = 2; num <= MAX; num++) {
        for (int k = 0; k <= MAX_S; k++) {
            for (int q = 0; q <= MAX_S; q++) {
                if (k + q > num) {
                    break;
                }
                // mask = 0
                f[num][k][q][0][0] = (f[num - 1][k][q][0][0] + f[num - 1][k][q][0][1] + f[num - 1][k][q][0][2]) * (num - k - q) / num;
                f[num][k][q][0][1] = (f[num - 1][k - 1][q][0][0] + f[num - 1][k - 1][q][0][2]) * (num - k) / num;
                f[num][k][q][0][2] = (f[num - 1][k][q - 1][0][0] + f[num - 1][k][q - 1][0][1]) * (num - q) / num;
                
                // mask = 1
                f[num][k][q][1][0] = (f[num - 1][k][q][1][0] + f[num - 1][k][q][1][1] + f[num - 1][k][q][1][2]) * (num - k - q) / num;
                f[num][k][q][1][1] = (f[num - 1][k - 1][q][1][0] + f[num - 1][k - 1][q][1][1] + f[num - 1][k - 1][q][1][2] + f[num - 1][k - 1][q][0][1]) * k / num;
                f[num][k][q][1][2] = (f[num - 1][k][q - 1][1][0] + f[num - 1][k][q - 1][1][1] + f[num - 1][k][q - 1][1][2]) * q / num;

                // mask = 2
                f[num][k][q][2][0] = (f[num - 1][k][q][2][0] + f[num - 1][k][q][2][1] + f[num - 1][k][q][2][2]) * (num - k - q) / num;
                f[num][k][q][2][1] = (f[num - 1][k - 1][q][2][0] + f[num - 1][k - 1][q][2][1] + f[num - 1][k - 1][q][2][2]) * k / num;
                f[num][k][q][2][2] = (f[num - 1][k][q - 1][2][0] + f[num - 1][k][q - 1][2][1] + f[num - 1][k][q - 1][2][2] + f[num - 1][k][q - 1][0][2]) * q / num;

                // mask = 3
                f[num][k][q][3][0] = (f[num - 1][k][q][3][0] + f[num - 1][k][q][3][1] + f[num - 1][k][q][3][2]) * (num - k - q) / num;
                f[num][k][q][3][1] = (f[num - 1][k - 1][q][3][0] + f[num - 1][k - 1][q][3][1] + f[num - 1][k - 1][q][3][2] + f[num - 1][k - 1][q][2][1]) * k / num;
                f[num][k][q][3][2] = (f[num - 1][k][q - 1][3][0] + f[num - 1][k][q - 1][3][1] + f[num - 1][k][q - 1][3][2] + f[num - 1][k][q - 1][1][2]) * q / num;
            }
        }
    }
}

int main() {
    freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    prepare();

    cout << f[4][2][2][3][0] + f[4][2][2][3][1] + f[4][2][2][3][2];

    return 0;
}