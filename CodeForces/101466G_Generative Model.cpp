#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;

vector<int> primes;
bool mark[MAX];
long long f[50];
int n;
string s;

void sieve(){
	mark[0] = mark[1] = 1;
	for (int i = 2; i < MAX; i++){
		if (mark[i])
			continue;
		primes.push_back(i);
		for (long long j = 1LL*i*i; j < MAX; j += i)
			mark[j] = 1;
	}
}

long long dp(int id){
	if (f[id] != -1)
		return f[id];
	if (id == n)
		return 1;
	if (s[id] == '0')
		return 0;
	long long ret = dp(id+1);
	if (id+1 < n){
		int tmp = (s[id] - '0')*10 + s[id+1]-'0';
		if (tmp <= 26)
			ret = (ret + dp(id+2)) % MOD;
	}
	return f[id] = ret;
}

string toString(int n){
	stringstream ss;
	ss << n;
	return ss.str();
}

int main(){
	ios::sync_with_stdio(false);

	sieve();
	while (cin >> n){
		s = "";
		long long res = 0;
		for (int i = 0; i < primes.size() && n > 1 && primes[i] <= n; i++){
			while (n % primes[i] == 0){
				s += toString(primes[i]);
				n /= primes[i];
			}
		}
		if (n > 1) s += toString(n);
		sort(s.begin(), s.end());
		n = s.length();
		do{
			memset(f, -1, sizeof(f));
			res = (res + dp(0)) % MOD;
		} while (next_permutation(s.begin(), s.end()));
		cout << res << "\n";
	}

	return 0;
}