#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define pb push_back

const int MAX = 1e6 + 10;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INF = 1e17;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct item {
	ll max, right, left, sum;
	int child_left, child_right;
};

item f[N * 20];
int cnt = 1;
int a[N], state[N];
int n, cur, n_query;

void build(int l = 1, int r = n, int pos = 1)
{
	if (l == r) {
		f[pos].sum = a[l];
		f[pos].left = a[l];
		f[pos].right = a[l];
		f[pos].max = a[l];
		f[pos].child_left = 0;
		f[pos].child_right = 0;
	} else {
		int m = l + r >> 1;
		int left = ++cnt;
		int right = ++cnt;
		build(l, m, left);
		build(m + 1, r, right);
		f[pos].max = max(max(f[left].max, f[right].max), f[left].right + f[right].left);
		f[pos].sum = f[left].sum + f[right].sum;
		f[pos].left = max(f[left].left, f[right].left + f[left].sum);
		f[pos].right = max(f[right].right, f[left].right + f[right].sum);
		f[pos].child_left = left;
		f[pos].child_right = right;
	}
}

void update(int x, int l, int r, int pos, int old)
{
	if (l == r && l == x) {
		f[pos].sum = a[l];
		f[pos].left = a[l];
		f[pos].right = a[l];
		f[pos].max = a[l];
		f[pos].child_left = 0;
		f[pos].child_right = 0;
	} else {
		int m = l + r >> 1;
		int left, right;
		if (m >= x) {
			left = ++cnt;
			right = f[old].child_right;
			update(x, l, m, left, f[old].child_left);
		} else {
			left = f[old].child_left;
			right = ++cnt;
			update(x, m + 1, r, right, f[old].child_right);
		}
		f[pos].max = max(max(f[left].max, f[right].max), f[left].right + f[right].left);
		f[pos].sum = f[left].sum + f[right].sum;
		f[pos].left = max(f[left].left, f[right].left + f[left].sum);
		f[pos].right = max(f[right].right, f[left].right + f[right].sum);
		f[pos].child_left = left;
		f[pos].child_right = right;
	}
}

item query(int u, int v, int l, int r, int pos) 
{
	if (l > v || r < u) {
		item ret;
		ret.sum = ret.left = ret.right = ret.max = -INF;
		return ret;
	}
	if (l >= u && r <= v) {
		return f[pos];
	} else {
		int m = l + r >> 1;
		item ret1 = query(u, v, l, m, f[pos].child_left);
		item ret2 = query(u, v, m + 1, r, f[pos].child_right);
		item ret;
		ret.max = max(max(ret1.max, ret2.max), ret1.right + ret2.left);
		ret.sum = ret1.sum + ret2.sum;
		ret.left = max(ret1.left, ret2.left + ret1.sum);
		ret.right = max(ret2.right, ret1.right + ret2.sum);
		return ret;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build();
	state[0] = 1;
	cur = 1;
	cin >> n_query;
	for (int i = 1; i <= n_query; i++) {
		int _type;
		int x, y;
		cin >> _type;
		if (_type == 1) {
			cin >> x >> y;
			a[x] = y;
			++cnt;
			int old_cur = cur;
			cur = cnt;
			state[i] = cnt;
			update(x, 1, n, cnt, old_cur);	
		} else if (_type == 2) {
			cin >> x >> y;
			cout << query(x, y, 1, n, cur).max << endl;
			state[i] = cur;
		} else if (_type == 3) {
			cin >> x;
			cur = state[x];
			state[i] = cur;
		}
	}
	return 0;
}