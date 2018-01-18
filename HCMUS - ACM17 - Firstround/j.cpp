#include <bits/stdc++.h> 


using namespace std;  

const int N = 1009; 
int dp[N][N]; 
char s[N], p[N]; 


int main () { 
	// freopen("input", "r", stdin);

	scanf("%s", s + 1); 
	scanf("%s", p + 1);
	int n = strlen(s + 1);  
	int m = strlen(p + 1);  


	int sum = n + m ;  
	dp[0][0] = 0; 
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) { 
			dp[i][j] = 0;  
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			dp[i][j] = max(dp[i][j], dp[i][j-1]);
			if (s[i] == p[j])
			dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);

		}
		// cout << dp[n][m] <<endl; 
	sum -= dp[n][m]; 

	printf("%d", sum); 


}