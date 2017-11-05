#include <bits/stdc++.h> 

using namespace std; 

int n, m;
int p[10009], a[10009];

int main () { 
	// freopen("text.in", "r", stdin);


	scanf("%d", &n); 
	for (int i = 0; i < n; i++) { 
		scanf("%d", &p[i]);
	}	
	scanf("%d", &m); 
	for (int j = 0; j < m; j++) {
		scanf("%d", &a[j]);
	}

	int vmin = 2 * (1e9) + 10;
	for (int i = 0; i <n; i++) { 
		int k;
		scanf("%d", &k); 
		for (int j = 0; j < k; j++) { 
			int x; 
			scanf("%d", &x);
			x--;  
			vmin = min(vmin, p[i] + a[x]); 
		}
	}
	int sum; 
	scanf("%d", &sum);
	printf("%d", max(0, (sum / vmin)  - 1));
}