#include <bits/stdc++.h>
using namespace std;

const int MAX = 1010;
const int INF = 1e9;

int f[MAX][4][4][2][2];
int vis[MAX][4][4][2][2];
map<char,int> pos;

int dp(int id, int l, int r, int mark) {
	if (vis[id][l][r][mark]) {
		return f[MAX][l][r][mark];
	}
	vis[id][l][r][mark] = 1;
	f[id][l][r][mark] = INF;
}

int main() {
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdin(false);

	pos['L'] = 0;
	pos['R'] = 1;
	pos['U'] = 2;
	pos['D'] = 3;
	cin >> n;
	cin >> s;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int l = 0; l < 2; l++) {
				for ()
			}
		}
	}
	// for (int i = 0; i < MAX; i++) {
	// 	for (int j = 0; j < 4; j++) {
	// 		for (int k = 0; k < 4; k++) {
	// 			f[i][j][k][0] = f[i][j][k][1] = INF;
	// 		}
	// 	}
	// }
	// f[0][0][1][0]
	
	return 0;
}