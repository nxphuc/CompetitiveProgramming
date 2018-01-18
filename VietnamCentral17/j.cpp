#include <bits/stdc++.h> 

using namespace std; 

long long Pow[70];

int find(long long x) {
	if (x == 1) 
		return 0; 
	if (x == 2) 
		return 1; 
	int cnt = 0;  
	int j = 0;
	while (x > 1) {
		int j = 0;  
		for (; Pow[j] < x; j++) { 
		}
		j--;
		cnt++; 
		// cout << x <<' ';
		x -= Pow[j]; 
		// cout <<"debug" << x <<endl; 
	}
	// cout <<cnt <<endl; 
	cnt %= 2;  
	if (cnt == 1) 
		return 1; 
	else return 0; 
}

int main () { 
	// freopen("test.in", "r", stdin); 
	long long n; 
	Pow[0] = 1;  
	for (int j = 1; j < 63; j++) 
		Pow[j] = Pow[j-1] * 2ll; 
	cin >> n;  
	n++; 
	cout << find(n); 
	n++; 
	cout << find(n); 
	n++; 
	cout << find(n); 
}