#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;

vector<string> list_string;
vector<char> list_sep;
map<string, int> str_id;
int mark[MAX][2];
int vis[MAX][2];
vector<pair<int, int>> graph[MAX][2];
int n;

void bfs(int id, int t) {
    queue<pair<int,int>> q;

    q.push(make_pair(id, t));
    vis[id][t] = 1;
    mark[id][t] = 1;
    
    while (!q.empty()) {
        auto vertex = q.front();
        q.pop();
        // cout << vertex.first << " " << vertex.second << "\n";
        for (auto nei: graph[vertex.first][vertex.second]) {
            if (!vis[nei.first][nei.second]) {
                vis[nei.first][nei.second] = 1;
                mark[nei.first][nei.second] = 1;
                q.push(nei);
            }
        }
    }
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    string s, t;
    while (cin >> s) {
        if (s.back() == '.' || s.back() == ',') {
            list_sep.push_back(s.back());
            s.pop_back();
        }
        else {
            list_sep.push_back(' ');
        }
        list_string.push_back(s);
        if (str_id.find(s) == str_id.end()) {
            str_id[s] = n++;
        }
    }

    int n_str = list_string.size();
    int s_id, t_id;

    for (int i = 1; i < n_str; i++) {
        if (list_sep[i - 1] == '.') {
            continue;
        }
        s = list_string[i - 1];
        t = list_string[i];
        s_id = str_id[s];
        t_id = str_id[t];
        graph[s_id][1].push_back(make_pair(t_id, 0));
        graph[t_id][0].push_back(make_pair(s_id, 1));
    }
    
    for (int i = 0; i < n_str; i++) {
        if (list_sep[i] == ',' && !vis[str_id[list_string[i]]][1]) {
            bfs(str_id[list_string[i]], 1);
        }
    }
    cout << list_string[0];
    for (int i = 1; i < n_str; i++) {
        if (list_sep[i - 1] != ' ') {
            cout << list_sep[i - 1] << " " << list_string[i];
            continue;
        }
        s = list_string[i - 1];
        t = list_string[i];
        if (mark[str_id[s]][1] || mark[str_id[t]][0]) {
            cout << ',';
        }
        cout << ' ' << list_string[i];
    }
    cout << list_sep[n_str - 1];

    return 0;
}