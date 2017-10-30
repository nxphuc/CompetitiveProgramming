// #include <bits/stdc++.h>
// using namespace std;

// vector<string> s, t;
// int r, c;

// int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
// int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

// char getXor(char x, char y){
// 	return ((x == '#') ^ (x == '#')) ? '#' : '.';
// }

// int invertRow(int i){
// 	int xorValue;
// 	for (int j = 0; j+1 < c; j++){
// 		xorValue = s[i][j];
// 		for (int d = 0; d < 7; d++)
// 			if (inRange(i + dx[d], j + dy[d]))
// 				xorValue = getXor(xorValue, t[i + dx[d]][j + dy[d]]);
// 		t[i+1][j+1] = xorValue;
// 	}
// 	if (t[i+1][c-1] == '#')
// 		return 0;
// 	xorValue = '.';
// 	for (int d = 0; d < 8; d++)
// 		if (inRange(i + dx[d], c-1 + dy[d]))
// 			xorValue = getXor(xorValue, t[])
// 	if (s[i][c-1] != t[i+1][c-2] || )
// 		return 0;
// 	return 1;
// }

// int invertCol(int j){
// 	int xorValue;
// 	for (int i = 0; i+1 < r; i++){
// 		xorValue = s[i][j];
// 		for (int d = 0; d < 7; d++)
// 			if (inRange(i + dx[d], j + dy[d]))
// 				xorValue = getXor(xorValue, t[i + dx[d]][j + dy[d]]);
// 		t[i+1][j+1] = xorValue;
// 	}
// 	if (s[r-1][j] != t[])
// 	return 0;
// }

// int validLastRow(){
// 	return 0;
// }

// int validLastCol(){
// 	return 0;
// }

// int invert(){
// 	t.assign(r, string(c, '.'));
// 	int failX = -1, failY = -1;
// 	for (int i = 0; i+1 < r; i++)
// 		if (!invertRow(i)){
// 			failX = i;
// 			break;
// 		}
// 	if (failX == -1)
// 		failX = validLastRow() ? -1 : r-1;
// 	if (failX != -1){
// 		t.assign(r, string(c, '.'));
// 		for (int j = 0; j+1 < c; j++)
// 			if (!invertCol(j)){
// 				failY = j;
// 				break;
// 			}
// 		if (failY == -1)
// 			failY = validLastCol() ? -1 : c-1;
// 	}
// 	return 1;
// }

// int main(){
// 	freopen("test.in", "rt", stdin);

// 	int r, c;
// 	vector<string> s, t;

// 	cin >> c >> r;
// 	s.resize(r);
// 	for (int i = 0; i < r; i++)
// 		cin >> s[i];

// 	while (invert(s, t, r, c))
// 		s = t, r -= 2, c -= 2;
	
// 	for (int i = 0; i < s.size(); i++)
// 		cout << s[i] << "\n";

// 	return 0;
// }