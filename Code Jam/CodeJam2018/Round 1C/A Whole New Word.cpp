#include <bits/stdc++.h>
using namespace std;

struct Node {
    map<char, Node*> child;
    int count_leaf;

    Node() {
        this->child.clear();
        this->count_leaf = 0;
    }
};

int mark[11][30];

void clearTrie(Node* root) {
    if (root == NULL) {
        return;
    }
    for (auto ch : root->child) {
        clearTrie(ch.second);
    }
    delete root;
}

void addWord(Node* root, string s) {
    Node* tmp = root;
    for (int i = 0; i < s.length(); i++) {
        int ch = s[i] - 'A';
        mark[i][ch] = 1;
        if (tmp->child.find(ch) == tmp->child.end()) {
            tmp->child[ch] = new Node();
        }
        tmp = tmp->child[ch];
    }
    tmp->count_leaf += 1;
}

string findWord(Node* root, int level, int length) {
    string s = "";
    if (level == length - 1) {
        for (int i = 0; i < 26; i++) {
            if (mark[level][i] && root->child.find(i) == root->child.end()) {
                s += char('A' + i);
                return s;
            }
        }
        return "";
    }
    for (int i = 0; i < 26; i++) {
        if (mark[level][i] && root->child.find(i) == root->child.end()) {
            s = char('A' + i);
            for (level = level + 1; level < length; level++) {
                for (int j = 0; j < 26; j++) {
                    if (mark[level][j]) {
                        s += char('A' + j);
                        break;
                    }
                }
            }
            return s;
        }
    }
    for (auto ch : root->child) {
        s = findWord(ch.second, level + 1, length);
        if (s != "") {
            return char(ch.first + 'A') + s;
        }
    }
    return "";
}

void doTestCase() {
    int n, l;
    string s;

    cin >> n >> l;

    Node* root = new Node();
    memset(mark, 0, sizeof(mark));

    for (int i = 0; i < n; i++) {
        cin >> s;
        addWord(root, s);
    }
    
    string res = findWord(root, 0, l);
    if (res == "") {
        res = "-";
    }
    cout << res << "\n";
    clearTrie(root);
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);
    
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cout << "Case #" << cs << ": ";
        doTestCase();
    }

    return 0;
}