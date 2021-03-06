#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

//Output:
// SA = The suffix array. Contains the n suffixes of txt sorted in lexicographical order.
//       Each suffix is represented as a single integer (the SAition of txt where it starts).
// iSA = The inverse of the suffix array. iSA[i] = the index of the suffix txt[i..n)
//        in the SA array. (In other words, SA[i] = k <==> iSA[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix txt[i..n) is smaller
//        than txt[j..n) if and only if iSA[i] < iSA[j]
const int MAX = 100010;
char txt[MAX]; //input
int iSA[MAX], SA[MAX]; //output
int cnt[MAX], ne[MAX]; //internal
bool bh[MAX], b2h[MAX];

bool smaller_first_char(int a, int b) {
    return txt[a] < txt[b];
}

void suffixSort(int n) {
    for (int i = 0; i < n; ++i)
        SA[i] = i;

    sort(SA, SA + n, smaller_first_char);

    for (int i = 0; i < n; ++i) {
        bh[i] = i == 0 || txt[SA[i]] != txt[SA[i - 1]];
        b2h[i] = false;
    }

    for (int h = 1; h < n; h <<= 1) {
        int buckets = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i + 1;
            while (j < n && !bh[j]) j++;
            ne[i] = j;
            buckets++;
        }
        if (buckets == n) break;

        for (int i = 0; i < n; i = ne[i]) {
            cnt[i] = 0;
            for (int j = i; j < ne[i]; ++j)
                iSA[SA[j]] = i;
        }

        cnt[iSA[n - h]]++;
        b2h[iSA[n - h]] = true;
        for (int i = 0; i < n; i = ne[i]) {
            for (int j = i; j < ne[i]; ++j) {
                int s = SA[j] - h;
                if (s >= 0) {
                    int head = iSA[s];
                    iSA[s] = head + cnt[head]++;
                    b2h[iSA[s]] = true;
                }
            }
            for (int j = i; j < ne[i]; ++j) {
                int s = SA[j] - h;
                if (s >= 0 && b2h[iSA[s]])
                for (int k = iSA[s] + 1; !bh[k] && b2h[k]; k++)
                    b2h[k] = false;
            }
        }
        for (int i = 0; i < n; ++i) {
            SA[iSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }

    for (int i = 0; i < n; ++i)
        iSA[SA[i]] = i;
}

int lcp[MAX];
// lcp[i] = length of the longest common prefix of suffix SA[i] and suffix SA[i-1]
// lcp[0] = 0
void getlcp(int n) {
    for (int i = 0; i < n; ++i)
        iSA[SA[i]] = i;

    lcp[0] = 0;

    for (int i = 0, h = 0; i < n; ++i)
    if (iSA[i] > 0){
        int j = SA[iSA[i] - 1];
        while (i + h < n && j + h < n && txt[i + h] == txt[j + h])
            h++;
        lcp[iSA[i]] = h;

        if (h > 0)
            h--;
    }
}

int main(){
    int len;
    scanf("%s", txt);
    len = strlen(txt);

    suffixSort(len);
    getlcp(len);
    for (int i = 0; i < len; ++i)
    {
        printf("%d %d\n", SA[i], lcp[i]);
        printf("%s\n", txt + SA[i]);
    }
    return 0;
}
