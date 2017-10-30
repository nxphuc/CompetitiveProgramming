/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX = 26;

struct Node{
	Node* child[MAX];
	int countLeaf;
};

Node* newNode(){
	Node* node = new Node;
	node->countLeaf = 0;
	for (int i = 0; i < MAX; i++)
		node->child[i] = NULL;
}

void insertWord(Node* root, char s[]){
	Node* tmp = root;
	int n = strlen(s);
	for (int i = 0; i < n; i++){
		if (!tmp->child[s[i] - 'a'])
			tmp->child[s[i] - 'a'] = newNode();
		tmp = tmp->child[s[i] - 'a'];
	}
	tmp->countLeaf++;
}

int traversal(Node* root, char s[], int n){
	if (!root)
		return 0;
	int cnt = 0;
	if (root->countLeaf){
		s[n] = 0;
		printf("%s\n", s);
		cnt = 1;
	}
	for (int i = 0; i < MAX; i++){
		s[n] = i+'a';
		cnt += traversal(root->child[i], s, n+1);
	}
	return cnt;
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int n;
	char s[25];
	Node* root = newNode();


	cin >> n;
	while (n--){
		cin >> s;
		insertWord(root, s);
	}
	cin >> n;
	for (int cs = 1; cs <= n; cs++){
		cin >> s;
		printf("Case #%d:\n", cs);

		int flag = 0;
		Node* tmp = root;
		for (int i = 0; i < strlen(s); i++)
			if (!tmp->child[s[i] - 'a']){
				flag = 1;
				break;
			}
			else
				tmp = tmp->child[s[i] - 'a'];

		if (flag){
			puts("No match.");
			continue;
		}
		for (int i = 0; i < MAX; i++)
			flag += traversal(tmp->child[i], s, strlen(s));
		if (!flag)
			puts("No match.");
	}

	return 0;
}