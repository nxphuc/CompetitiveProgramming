#include <bits/stdc++.h>
using namespace std;

const int MAX = 110;
const int INF = 1e9;

int m, n;
int a[MAX][MAX];
int c[MAX], r[MAX];
int res;

int main(){
	ios::sync_with_stdio(false);

	cin >> m >> n;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			if(m < n)
				cin >> a[i][j];
			else
				cin >> a[j][i];
	string row = "H", col = "C";
	if (m >= n){
		swap(m,n);
		swap(row,col);
	}
	for(int i = 0; i < m; i++){
		int t = INF;	
		for(int j = 0; j < n; j++)
			t = min(t ,a[i][j]);	
		for(int j = 0; j < n; j++)
			a[i][j] -= t;
		r[i]=t;
		res += t;
	}

	for(int j = 0; j < n; j++){
		for(int i = 1; i < m; i++){
			if(a[i][j] != a[i-1][j]){
				cout << -1;
				return 0;
			}
		}
		c[j] = a[0][j];
		res += c[j];
	}

	cout << res << "\n";

	if (row == "H"){
		for(int i = 0; i < m; i++)
			for(int k = 0; k < r[i]; k++)
				cout << row << " " << i+1 << "\n";
		for(int j = 0; j < n; j++)
			for(int k = 0; k < c[j]; k++)
				cout << col << " " << j+1 << "\n";
	}
	else{
		for(int j = 0; j < n; j++)
			for(int k = 0; k < c[j]; k++)
				cout << col << " " << j+1 << "\n";
		for(int i = 0; i < m; i++)
			for(int k = 0; k < r[i]; k++)
				cout << row << " " << i+1 << "\n";
	}
	return 0;
}