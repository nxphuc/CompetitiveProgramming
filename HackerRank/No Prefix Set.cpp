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

bool isEmpty(struct node *pNode)
{
	for (int i = 0; i < MAX; i++)
	{
		if (pNode->child[i] != NULL)
		{
			return false;
		}
	}
	return true;
}

bool addword(struct node *root, string s)
{
	int ch;
	bool flag = true;
	struct node *temp = root;

	for (int i = 0; i < s.size(); i++){
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL)
			temp->child[ch] = newNode();
		temp = temp->child[ch];
		if (temp->countLeaf > 0){
			return false;			// co 1 tu la ma no la tien to cua tu dang them vao trie
		}
	}
	temp->countLeaf++;
	// kiem tra neu tu vua add la tien to cua mot tu khac co trong trie thi return fasle
	// no la tien to neu nhu node temp co con (tuc co tu khac ben duoi)
	return isEmpty(temp);
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

	node *trie = newNode();
	int n;
	string str;

	cin >> n;
	while (n--){
		cin >> str;
		if (!addword(trie, str)){
			cout << "BAD SET\n";
			cout << str << "\n";
			return 0;
		}
	}
	cout << "GOOD SET";

	return 0;
}