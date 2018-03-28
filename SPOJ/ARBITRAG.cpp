#include <bits/stdc++.h>
using namespace std;

const int MAX = 40;
const double EPS = 1e-9;

string currencies[MAX];
double arbitrage[MAX][MAX];
int n, m;

int findCurrency(string s){
	for (int i = 0; i < n; i++)
		if (currencies[i] == s)
			return i;
	return -1;
}

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arbitrage[i][j] < arbitrage[i][k] * arbitrage[k][j]) {
                    arbitrage[i][j] = arbitrage[i][k] * arbitrage[k][j];
                }
            }
        }
    }
}

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int flag, cs = 0;
	string u, v;
	double w;

	while (1){
		cin >> n;

		if (n == 0)
			break;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    arbitrage[i][j] = 0;
                }
                else {
                    arbitrage[i][j] = 1;
                }
            }
        }

		cs++;

		for (int i = 0; i < n; i++)
			cin >> currencies[i];
		cin >> m;
		for (int i = 0; i < m; i++){
			cin >> u >> w >> v;
            arbitrage[findCurrency(u)][findCurrency(v)] = w;
		}

		floydWarshall();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (arbitrage[i][i] > 1) {
                flag = true;
                break;
            }
        }
		cout << "Case " << cs << ": " << (flag ? "Yes" : "No") << "\n";
	}

    return 0;
}