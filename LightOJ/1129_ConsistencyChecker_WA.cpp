#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 6e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

bool flag;

struct node {
	bool en;
	int next[11];
	int cnt = 0;
	// node() {
	// 	for (int i = 0; i < 10; i++) {
	// 		next[i] = -1;
	// 	}
	// }
} tree[MAX];

void insert(string str, int len) {
	int cur;
	for (int i = 0; i < len; i++) {
		int id = str[i] - '0';
		if (curr->next[id] == NULL) {
			flag = 1;
			curr->next[id] = new node();
		}
		curr = curr->next[id];
	}
	curr->en = true;
}

void del(node* cur) {
	for (int i = 0; i < 10; i++) {
		if (cur->next[i]) {
			del(cur->next[i]);
		}
	}
	delete cur;
}

int main(){
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	map<char, string> mp;
	vector<string> ara;
	int t, n, k = 0, flag;

	cin >> t;
	while (t--) {
		ara.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			ara.push_back(s);
		}
		sort(ara.begin(), ara.end());

	}
	
	return 0;
}