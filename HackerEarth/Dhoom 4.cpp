#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e5;
const int MAX = 1e5 + 10;

vector<long long> a;
int n;
long long s, t, nxt;
int f[MAX];
queue<int> q;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	cin >> s >> t;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	memset(f,-1,sizeof(f));
   	f[s] = 0;
   	q.push(s);
   	while (!q.empty()){
   		s = q.front();
   		q.pop();
   		for (int v: a){
   			nxt = (s*v) % MOD;
   			if (f[nxt] == -1){
   				f[nxt] = f[s] + 1;
   				if (nxt == t)
   					break;
   			   	q.push(nxt);
   			}
   		}
   	}
   	cout << f[t];

	return 0;
}