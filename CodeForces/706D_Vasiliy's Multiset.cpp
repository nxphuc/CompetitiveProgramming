#include <bits/stdc++.h>
using namespace std;

struct Node {
	Node* child[2];
	int countLeaf;
	int countPass;
};

Node* newNode() {
	Node* node = new Node();
	node->child[0] = node->child[1] = NULL;
	node->countLeaf = 0;
	node->countPass = 0;
	return node;
}

void addWord(Node *&root, int x) {
	Node *temp = root;
	for (int i = 30; i >= 0; i--) {
		int ch = (x >> i) & 1;
		if (temp->child[ch] == NULL) {
			temp->child[ch] = newNode();
		}
		temp = temp->child[ch];
		temp->countPass++;
	}
	temp->countLeaf++;
}

void removeWord(Node *&root, int x, int level) {
	if (level == 0) {
		root->countLeaf--;
		return;
	}
	int ch = (x >> level) & 1;
	// cout << "# " << x << " " << level << " " << ch << "\n";
	removeWord(root->child[ch], x, level - 1);
	// cout << "@ " << x << " " << root->child[ch]->countPass << " " << level << "\n";
	root->child[ch]->countPass--;
	// cout << "# " << x << " " << root->child[ch]->countPass << " " << level << "\n";
	if (root->child[ch]->countPass == 0) {
		delete root->child[ch];
		root->child[ch] = NULL;
	}
}

void removeWord(Node *&root, int x) {
	removeWord(root, x, 30);
}

int query(Node *root, int x) {
	int res = 0;
	for (int i = 30; i >= 0; i--) {
		int ch = (x >> i) & 1;
		if (root->child[1 - ch] != NULL) {
			res += 1 << i;
			root = root->child[1 - ch];
		}
		else {
			root = root->child[ch];
		}
	}
	return res;
}

int main() {
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	Node *root = newNode();
	int n, x;
	char ch;

	cin >> n;
	while (n--) {
		cin >> ch >> x;
		if (ch == '+') {
			addWord(root, x);
		}
		else {
			if (ch == '-') {
				removeWord(root, x);
			}
			else {
				cout << query(root, x) << "\n";
			}
		}
	}

	return 0;
}