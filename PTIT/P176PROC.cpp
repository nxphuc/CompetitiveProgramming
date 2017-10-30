/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 1e5 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct Node{
	int val, numTail, numPass;
	Node* child[26];

	Node(int val = 0, int numTail = 0, int numPass = 0) : val(val), numTail(numTail), numPass(numPass) {
		REP(i,0,26)
			child[i] = NULL;
	}
};

int insert(Node* root, string s){
	int i = 0;
	char ch;
	Node* nChild = NULL;
	Node* cur = root;

	// s = "#" + s;
	while (i < s.length()){
		ch = s[i++];
		nChild = cur->child[ch - 'a'];
		if (!nChild){
			// if (cur->val != '#')
			// 	return 0;
			cur->child[ch - 'a'] = new Node(ch - 'a', 0, 1);
		}
		else{
			nChild->numPass++;
			if (nChild->numTail)
				return 0;
		}
		cur = cur->child[ch - 'a'];
	}
	cur->numTail++;
	cur->numPass--;
	return !(cur->numPass);
}

int n;
string s[MAX];

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	Node* root = new Node('#');

	// insert(root, "#");
	cin >> n;
	REP(i,0,n) cin >> s[i];
	// sort(s, s+n);
	REP(i,0,n){
		if (!insert(root, s[i])){
			cout << "BAD SET\n";
			cout << s[i] << "\n";
			return 0;
		}
	}
	cout << "GOOD SET";

	return 0;
}