#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    
    // code here
    string s;
    cin >> s;
    cout << s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'B' || (s[i] == 'A' && s[i-1] == 'B')) {
            cout << s[i];
        }
    }
    
    return 0;
}