#include <bits/stdc++.h>
using namespace std;

const int MAX = 3e5 + 10;

struct Node{
	int cnt;
	Node* child[2];

	Node(int cnt = 0) : cnt(cnt){
		child[0] = child[1] = NULL;
	}
};

void add(Node* root, int val){
	for (int i = 19; i >= 0; i--){
		int b = (val >> i) & 1;
		if (root->child[b] == NULL){
			root->child[b] = new Node();
		}
		root->cnt++;
		root = root->child[b];
	}
	root->cnt++;
}

int query(Node* root, int val){
	int res = 0;
	int bit;
	for (int i = 19; i >= 0 && root; i--){
		bit = (val >> i) & 1;
		if (root->child[bit] == NULL)
			return res;
		if (root->child[bit]->cnt == (1 << i)){
			res |= 1 << i;
			root = root->child[1-bit];
		}
		else{
			root = root->child[bit];
		}
	}
	return res;
}

int a[MAX];

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	Node* root = new Node();
	int n, m, x, sum_xor;

	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	n = unique(a, a+n) - a;
	for (int i = 0; i < n; i++){
		add(root, a[i]);
	}
	sum_xor = 0;
	while (m--){
		cin >> x;
		sum_xor ^= x;
		cout << query(root, sum_xor) << "\n";
	}

	return 0;
}
