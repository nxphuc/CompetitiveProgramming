#include <stdio.h>
#include <string.h>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
const int MAX = 1e6 + 10;
int n, pal[MAX * 2];
char s[MAX];

void constructManacher() {
    int m = n << 1;

    for (int i = 0, j = 0, k; i < m;
        i += k, j = max(j - k, 0)) {
        for (;
            i >= j && i + j + 1 < m &&
            s[(i - j) / 2] == s[(i + j + 1) / 2];
            ++j);

        pal[i] = j;

        for (k = 1;
            i >= k &&
            pal[i] >= k &&
            pal[i - k] != pal[i] - k;
            ++k)
            pal[i + k] = min(pal[i - k], pal[i] - k);
    }
}

int main() {
    //scanf("%s", s);
    strcpy(s, "abaabaaba");
    n = strlen(s);
    constructManacher();

    //print length odd
    for (int i = 0; i < (n << 1); i += 2)
        printf("%d ", pal[i]);
    printf("\n");
    //print length even
    for (int i = 1; i < (n << 1); i += 2)
        printf("%d ", pal[i]);
    return 0;
}
