#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10; 

int n, m; 
int a[N], b[N];
int cnt[N];
long long sum[N], T[N], f[N]; 
const int vmax = 1e4; 

int main () { 
	// freopen("test.in", "r", stdin); 

	scanf("%d", &n); 
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]); 
	scanf("%d", &m); 
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		cnt[b[i]] ++; 
		sum[b[i]] += b[i];
		f[b[i]] += i; 
		T[b[i]] += (long long)b[i] * i;	
	}   
	for (int i = 1; i <= 1e4; i++) { 
		cnt[i] += cnt[i-1]; 
		sum[i] += sum[i-1]; 
		T[i] += T[i-1]; 
		f[i] += f[i-1];
	}
	long long ans = 0; 
	for (int i = 1; i <= n; i++) {
		// less than a[i] 
		ans += (long long)i * (long long)a[i] * cnt[a[i]-1]; 
		ans += T[a[i]-1];
		ans -= (long long)i * sum[a[i]-1];
		ans -= (long long)a[i] * f[a[i]-1]; 

		// more than a[i] 
		ans += (long long)i * (sum[vmax] - sum[a[i]]);
		ans += (long long)a[i] * (f[vmax] - f[a[i]]); 
		ans -= (long long)i * (long long)a[i] * (cnt[vmax] - cnt[a[i]]);
		ans -= T[vmax] - T[a[i]]; 
	}

	printf("%lld", ans); 

}