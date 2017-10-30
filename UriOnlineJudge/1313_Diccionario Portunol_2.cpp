#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 26;

struct node
{
	struct node *child[MAX];
	int countLeaf;
};

struct node *newNode()
{
	struct node *newNode = new struct node;
	newNode->countLeaf = 0;
	for (int i = 0; i < MAX; i++)
	{
		newNode->child[i] = NULL;
	}
	return newNode;
}

void addword(struct node *root, string s)
{
	int ch;
	struct node *temp = root;
	for (int i = 0; i < s.size(); i++){
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL)
			temp->child[ch] = newNode();
		temp = temp->child[ch];
	}
	temp->countLeaf++;
}

long long startWith[26];
long long suffixStateCount;

void suffixTraversal(node* pNode, int level){
	suffixStateCount++;
	for (int i = 0; i < 26; i++){
		if (!pNode->child[i])
			continue;
		if (level > 0) startWith[i]++;
		suffixTraversal(pNode->child[i], level + 1);
	}
}

long long prefixTraversal(node* pNode, int level){
	long long result = 0;
	if (level > 0) result += suffixStateCount;
	for (int i = 0; i < 26; i++){
		if (!pNode->child[i])
			continue;
		if (level > 0)
			result -= startWith[i];
		result += prefixTraversal(pNode->child[i], level+1);
	}
	return result;
}

void clearTree(node *pNode)
{
	for (int i = 0; i < MAX; i++)
	{
		if (pNode->child[i])
		{
			clearTree(pNode->child[i]);
			delete pNode->child[i];
		}
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	node *suffixTrie, *prefixTrie;
	int p, s;
	string str;

	while (1){
		cin >> p >> s;
		if (!p && !s)
			break;

		suffixTrie = newNode();
		prefixTrie = newNode();
		for (int i = 0; i < 26; i++)
			startWith[i] = 0;
		suffixStateCount = 0;

		for (int i = 0; i < p; i++){
			cin >> str;
			addword(prefixTrie, str);
		}
		for (int i = 0; i < s; i++){
			cin >> str;
			reverse(str.begin(), str.end());
			addword(suffixTrie, str);
		}
		suffixTraversal(suffixTrie, 0);
		suffixStateCount--;
		cout << prefixTraversal(prefixTrie, 0) << "\n";
	}

	return 0;
}