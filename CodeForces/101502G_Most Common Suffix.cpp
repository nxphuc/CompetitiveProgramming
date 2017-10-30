#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

struct Node {
	int cnt;
	Node* child[30];

	Node(int cnt = 0) : cnt(cnt) {
		for (int i = 0; i < 30; i++) {
			child[i] = NULL;
		}
	}
};

int max_suffix[MAX];
char s[MAX];

void add(Node* root, const string& s) {
	Node* cur = root;
	int nxt;
	int len = 0;
	for (const char& ch: s) {
		len++;
		nxt = ch - 'a';
		if (cur->child[nxt] == NULL) {
			cur->child[nxt] = new Node();
		}
		cur = cur->child[nxt];
		cur->cnt++;
		max_suffix[len] = max(max_suffix[len], cur->cnt);
	}
}

void clear(Node* &root) {
	if (root == NULL) {
		return;
	}
	for (auto& ch: root->child) {
		clear(ch);
		ch = NULL;
	}
	delete root;
	root = NULL;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n, q, x;
	string str;
	Node *trie;

	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &q);
		trie = new Node();
		memset(max_suffix, 0, sizeof(max_suffix));
		while (n--) {
			scanf("%s", s);
			str = s;
			reverse(str.begin(), str.end());
			add(trie, str);
		}
		while (q--) {
			scanf("%d", &x);
			printf("%d\n", max_suffix[x]);
		}
		clear(trie);
	}

	return 0;
}