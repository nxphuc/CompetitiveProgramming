#include <bits/stdc++.h>
using namespace std;

struct Trie{
	int cnt;
	Trie* child[2];

	Trie(cnt = 0) : cnt(cnt) {
		child[0] = child[1] = NULL;
	}
};

void insertNumber(Trie* root, int val){
	Trie* tmp = root;
	int nxt;
	for (int i = 29; i >= 0; i--){
		nxt = val & (1 << i);
		if (!(tmp->child[nxt]))
			tmp->child[nxt] = new Trie();
		tmp = tmp->child[nxt];
		tmp->cnt++; 
	}
}

void removeNumber(Trie* root, int val, int id = 29){
    Trie* tmp = root;
	for (int i = 29; i >= 0; i--){
		tmp = tmp->child[val & (1 << i)];
		tmp->cnt--; 
	}
}

int countNumber(Trie* root, int x, int y, int i = 29){
	if (!root) return 0;
	if (!i) return root->cnt;

	if (y & (1 << i)){
		
	}

	if (!(x ^ y) & (1 << i))
		return countNumber(root->child[nxt], x, y, i-1);
	return (root->child[0] ? root->child[0]->cnt : 0) + countNumber(root->child[1], x, y, i-1);
}

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	Trie trie = new Trie();
	cin >> q;

	return 0;
}