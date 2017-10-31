////////////////////////////////////////////////////
// Construct:
// Automaton sa; for(char c : s) sa.extend(c);
// 1. Number of distinct substr:
//    - Find number of different paths --> DFS on SA
//    - f[u] = 1 + sum( f[v] for v in s[u].next
// 2. Number of occurrences of a substr:
//    - Initially, in extend: s[cur].cnt = 1; s[clone].cnt = 0;
//    - for(it : reverse order)
//        p = nodes[it->second].link;
//        nodes[p].cnt += nodes[it->second].cnt
// 3. Find total length of different substrings:
//    - We have f[u] = number of strings starting from node u
//    - ans[u] = sum(ans[v] + d[v] for v in next[u])
// 4. Lexicographically k-th substring
//    - Based on number of different substring
// 5. Smallest cyclic shift
//    - Build SA of S+S, then just follow smallest link
// 6. Find first occurrence
//    - firstpos[cur] = len[cur] - 1, firstpos[clone] = firstpos[q]
//
// Demo: count number of distinct substring and total length after add each character
// Time complexity: O(N)
////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;
const int ALPHABET = 30;

struct Node{
    int len, link;
    long long numPath, sumLength;
    int next[ALPHABET];
};

Node s[MAX << 1];

struct SuffixAutomaton{
    int size, last;
    long long numSubstring, totalLength;

    SuffixAutomaton(){
        reset();
    }

    void reset(){
        s[0].len = 0;
        s[0].link = -1;
        s[0].numPath = 1;
        s[0].sumLength = 0;
        memset(s[0].next, 0, sizeof(int)*ALPHABET);
        last = 0;
        size = 1;
        numSubstring = totalLength = 0;
    }

    void extend(int ch){
        ch -= 'a';
        int cur = size++;
        memset(s[cur].next, 0, sizeof(int)*ALPHABET);
        s[cur].numPath = 0;
        s[cur].sumLength = 0;
        s[cur].len = s[last].len + 1;

        int p;
        for (p = last; p != -1 && !s[p].next[ch]; p = s[p].link){
            s[p].next[ch] = cur;
            s[cur].numPath += s[p].numPath;
            s[cur].sumLength += s[p].sumLength + s[p].numPath;
            numSubstring += s[p].numPath;
            totalLength += s[p].sumLength + s[p].numPath;
        }
        if (p == -1)
            s[cur].link = 0;
        else{
            int q = s[p].next[ch];
            if (s[p].len + 1 == s[q].len)
                s[cur].link = q;
            else{
                int clone = size++;
                s[clone].len = s[p].len + 1;
                s[clone].numPath = 0;
                memcpy(s[clone].next, s[q].next, sizeof(int)*ALPHABET);
                s[clone].link = s[q].link;

                for (; p != -1 && s[p].next[ch] == q; p = s[p].link){
                    s[p].next[ch] = clone;
                    s[q].numPath -= s[p].numPath;
                    s[q].sumLength -= s[p].numPath + s[p].sumLength;
                    s[clone].numPath += s[p].numPath;   
                    s[clone].sumLength += s[p].numPath + s[p].sumLength;
                }
                s[q].link = s[cur].link = clone;
            }
        }
        last = cur;
    }

    long long countSubstring(){
        return numSubstring;
    }
    
    long long totalLengthSubstring(){
        return totalLength;
    }
};

int main(){
    freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    string s;
    SuffixAutomaton sa;

    while (cin >> s){
        sa.reset();

        for (char ch : s) {
            sa.extend(ch);
            cout << sa.countSubstring() << " " << sa.totalLengthSubstring() << "\n";
        }
    }

    return 0;
}