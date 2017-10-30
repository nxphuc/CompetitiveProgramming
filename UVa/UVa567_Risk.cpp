#include <bits/stdc++.h>
using namespace std;

int main(){
	// ios::sync_with_stdio(false);

	int cs, n, x, y;
	int f[21][21];

	cs = 1;
	while (1){
		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= 20; j++)
				f[i][j] = i == j ? 0 : 100;
		for (int i = 1; i < 20; i++){
			if (!cin >> n) return 0;
			while (n--){
				cin >> x;
				f[i][x] = f[x][i] = 1;
			}
		}

		for (int k = 1; k <= 20; k++)
			for (int i = 1; i <= 20; i++)
				for (int j = 1; j <= 20; j++)
					f[i][j] = min(f[i][k] + f[k][j], f[i][j]);

		cout << "Test Set #" << cs++ << "\n";
		cin >> n;
		while (n--){
			cin >> x >> y;
			cout << setw(2) << x << " to " << setw(2) << y << ": " << f[x][y] << "\n";
		}
	}
}