#include <bits/stdc++.h>
using namespace std;


#define pb push_back

const int MAX = 1e6 + 10;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;
int origin_k;

int cnt[N][10], cnt_less[N][10];
vector <int> v[10];
int di[N];
int n;
char s[N];

int solve(int digit, int l, int r, int k, int pos) {
	cout <<"dgdfg"<<endl; 
	if (v[digit].size() == 0) 
		return solve(digit - 1, l, r, k, pos); 
	if (digit == 0)
		return 0;
	cout << k <<endl; 
	if (cnt[r][digit] - cnt[l-1][digit] >= k)
		return digit; 
	k -= cnt[r][digit] - cnt[l-1][digit];
	int l1 = r + 1;
	int ll = 0;
	int rr = v[digit].size() - 1;
	while (ll <= rr) {
		int midd = (ll + rr) >> 1;
		if (v[digit][midd] >= l) {
			l1 = midd;
			rr = midd-1;
		} else ll  = midd + 1;
	}
	int r1 = l - 1;
	ll = 0;
	rr = v[digit].size() - 1;
	while (ll <= rr) {
		int midd = (ll + rr) >> 1;
		if (v[digit][midd] <= r) {
			r1 = midd;
			ll = midd + 1;
		} else rr = midd-1;
	}

	// co khoang l1 .. r1
	ll = l1;
	rr = r1;
	int temp = -1;
	cout <<"k "<< k <<endl; 
	while (ll <= rr) {

		int midd = (ll + rr) >> 1;
		if (cnt_less[digit][r] - cnt_less[digit][v[digit][midd]-1] <= k) {
			temp = midd;
			rr = midd-1;
		} else ll = midd + 1;
	} 
	cout << digit <<' '<< pos <<' '<< temp <<endl;
	if (pos <= temp) 
		return digit; 
	origin_k -= temp;
	pos -= temp; 
	if (cnt_less[digit][r] - cnt_less[digit][v[digit][temp]-1] == k) {
		// lui ve  origin_k - pos + 1 phaanf tu
		// n - (oorigin_k - pos + 1) + 1
		// n - origin_k + pos - 1 + 1
		return di[n - origin_k + pos];
	} else {
		cout << v[digit][temp] - 1 <<' '<< r <<endl; 
		cout << cnt_less[9][9]<< ' '<< cnt_less[8][9] <<endl; 
		cout <<"bug" <<cnt_less[digit][r] - cnt_less[digit][v[digit][temp]-1] <<endl; 
		k-= cnt_less[digit][r] - cnt_less[digit][v[digit][temp]-1];
		if (n - v[digit][temp] + 1 >= origin_k - pos + 1) {
			return di[n - origin_k + pos];
		}
		return solve(digit - 1, (temp == 0 ? l : max(l, v[digit][temp-1] + 1)), v[digit][temp] - 1, k, pos);
		// [max(l, v[temp - 1] + 1) , v[temp] - 1]
	}

}

int main () {

	freopen("input", "r", stdin);

	scanf("%s", s + 1);
	int query;
	scanf("%d", &query);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		di[i] = s[i] - '0';
	for (int i = 1; i <= n; i++) {
		v[di[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 10; j++) {
			cnt[i][j] = cnt[i-1][j] + (di[i] == j);
			cnt_less[i][j] = cnt_less[i-1][j] + (di[i] < j);
		}
	while (query --) {
		int k, l;
		scanf("%d %d", &k, &l);
		origin_k = k ;
		printf("%d", solve(9, 1, n, k, l));
// puts("OK");
	}
}
