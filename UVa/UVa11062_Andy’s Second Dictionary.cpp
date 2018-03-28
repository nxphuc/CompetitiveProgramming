#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    string line, text;
    while (getline(cin, line)) {
        if (line == "") {
            continue;
        }
        text += line;
        if (text[text.length() - 1] != '-') {
            text += ' ';
        }
        else {
            text.erase(text.length() - 1);
        }
    }
    int n = text.length();
    for (int i = 0; i < n; i++) {
        if (isalpha(text[i])) {
            text[i] = tolower(text[i]);
        }
        else if (text[i] != '-') {
            text[i] = ' ';
        }
    }
    stringstream ss(text);
    set<string> words;
    while (ss >> line) {
        words.insert(line);
    }
    for (set<string>::iterator it = words.begin(); it != words.end(); it++) {
        cout << *it << "\n";
    }

    return 0;
}