#include <bits/stdc++.h>
using namespace std;

struct Trie{
	int isLeaf;
	Trie* child[10];

	Trie(int isLeaf = 0) : isLeaf(isLeaf){
		for (int i = 0; i < 10; i++)
			child[i] = NULL;
	}
};

void insertWord(Trie* root, string s){
	Trie* tmp = root;
	for (char ch : s){
		if (!(tmp->child[ch - '0']))
			tmp->child[ch - '0'] = new Trie();
		tmp = tmp->child[ch - '0'];
	}
	tmp->isLeaf = 1;
}

void removeTrie(Trie*& root){
	if (!root)
		return;
	for (int i = 0; i < 10; i++)
		removeTrie(root->child[i]);
	delete root;
	root = NULL;	
}

int isValid(Trie* root){
	if (!root)
		return 1;
	if (root->isLeaf){
		for (int i = 0; i < 10; i++)
			if (root->child[i])
				return 0;
	}
	for (int i = 0; i < 10; i++)
		if (!isValid(root->child[i]))
			return 0;
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	
	int t, n;
	Trie* trie;
	string s;

	cin >> t;
	while (t--){
		trie = new Trie();
		cin >> n;
		while (n--){
			cin >> s;
			insertWord(trie, s);
		}

		cout << (isValid(trie) ? "YES\n" : "NO\n");
		removeTrie(trie);
	}
	return 0;
}