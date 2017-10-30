#include <bits/stdc++.h>
using namespace std;

const int MAX = 110;

int f[MAX][MAX];
string g[MAX][MAX];
string s;
int n;

string makeBrackets(){
	stack<char> st;
	for (int i = 0; i < n; i++){
		if (s[i] == '(')
			st.push('(');
		else
			if (st.empty() || st.top() == ')')
				st.push(')');
			else
				st.pop();
	}
	while (!st.empty()){
		if (st.top() == ')')
			s = "(" + s;
		else
			s = s + ")";
		st.pop();
	}
	return s;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		s[i] = s[i] == '(' ? '(' : ')';
	memset(f, -1, sizeof(f));
	cout << makeBrackets();

	return 0;
}