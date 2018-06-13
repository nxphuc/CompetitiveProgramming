#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n;
    priority_queue<pii, vector<pii>, greater<pii>> min_q;
    priority_queue<pii> max_q;

    cin >> n;
    for (int x, i = 1; i <= n; i++) {
        cin >> x;
        min_q.push(make_pair(x, i));
    }

    string s;
    cin >> s;
    for (char ch : s) {
        if (ch == '0') {
            pii tmp = min_q.top();
            min_q.pop();
            cout << tmp.second << " ";
            max_q.push(tmp);
        }
        else {
            pii tmp = max_q.top();
            max_q.pop();
            cout << tmp.second << " ";
        }
    }

    return 0;
}