#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define pb push_back

const int MAX = 1e6 + 10;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct item
{
	int right, left, top, bot;
};

int f1[N * 4], f2[N * 4];
int n, m, k;
item a[N], b[N];
int ITmax[N * 4], zipmax[N * 4];

bool cmp1(const item &x, const item &y)
{
	if (x.right == y.right) return x.bot < y.bot;
	else return x.right < y.right;
}

bool cmp2(const item &x, const item &y)
{
	if (x.left == y.left) return x.bot < y.bot;
	else return x.left < y.left;
}

void update1(int x, int val, int l = 1, int r = n, int pos = 1)
{
	if (l > x || r < x) return;
	if (l == r && l == x) {
		f1[pos] += val;
		return;
	}
	int m = l + r >> 1;
	int left = pos << 1;
	int right = (pos << 1) + 1;
	update1(x, val, l, m, left);
	update1(x, val, m + 1, r, right);
	f1[pos] = f1[left] + f1[right];
}

void update2(int x, int val, int l = 1, int r = n, int pos = 1)
{
	if (l > x || r < x) return;
	if (l == r && l == x) {
		f2[pos] += val;
		return;
	}
	int m = l + r >> 1;
	int left = pos << 1;
	int right = (pos << 1) + 1;
	update2(x, val, l, m, left);
	update2(x, val, m + 1, r, right);
	f2[pos] = f2[left] + f2[right];
}

int query1(int u, int v, int l = 1, int r = n, int pos = 1)
{
	if (u > v) return 0;
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return f1[pos];
	int m = l + r >> 1;
	int left = pos << 1;
	int right = (pos << 1) + 1;
	int ret1 = query1(u, v, l, m, left);
	int ret2 = query1(u, v, m + 1, r, right);
	return ret1 + ret2;
}

int query2(int u, int v, int l = 1, int r = n, int pos = 1)
{
	if (u > v) return 0;
	if (r < u || l > v) return 0;
	if (u <= l && r <= v) return f2[pos];
	int m = l + r >> 1;
	int left = pos << 1;
	int right = (pos << 1) + 1;
	int ret1 = query2(u, v, l, m, left);
	int ret2 = query2(u, v, m + 1, r, right);
	return ret1 + ret2;
}

void build(int i, int l, int r) { 
	if (l > r) return; 
	if (l == r) { 
		ITmax[i] = 0;  
		zipmax[i] = 0; 
		return; 
	}
	int mid = (l + r) >> 1; 
	build(i << 1, l, mid); 
	build((i << 1) + 1, mid + 1, r); 
}

void lazy_update(int i) { 
	zipmax[i << 1] += zipmax[i]; 
	zipmax[(i << 1) + 1] += zipmax[i];  
	ITmax[i << 1] += zipmax[i << 1];
	ITmax[(i << 1) + 1] += zipmax[(i << 1) + 1];  
	zipmax[i] = 0;  
}

void update(int i, int l, int r, int u, int v, int val) {
	if (l > v || r < u || l > r) 
		return; 
	if (l >= u && r <= v) { 
		ITmax[i] += val; 
		zipmax[i] += val;
		return ; 
	} 
	if (zipmax[i]) { 
		lazy_update(i); 
	}
	int mid = (l + r) >> 1;  
	update(i << 1, l, mid, u, v, val); 
	update((i << 1) + 1, mid + 1, r, u, v, val); 
	ITmax[i] = max(ITmax[i << 1], ITmax[(i << 1) + 1]); 
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		a[i].top = b[i].top = y1;
		a[i].bot = b[i].bot = y2;
		a[i].left = b[i].left = x1;
		a[i].right = b[i].right = x2;
	}
	int ans = 0;  

	sort(a, a + m, cmp1); 
	sort(b, b + m, cmp2);
	build(1, 0, n); 
	int u = 0, v = 0;
	for (int i = 0; i < m; i++) {

		int x = a[i].right;
		while (u < m && a[u].right < x) { 
			update(1, 1, n, max(1, a[u].top - k + 1), a[u].bot, -1);
			u++;
		}
		while (v < m && a[v].left < x + k) { 
			update(1, 1, n, max(1, a[v].top - k + 1), a[v].bot, 1);
			v++;
		}
		ans = max(ans, ITmax[1]); 
	}
	cout << ans <<endl; 

	return 0; 

	
}