#include <bits/stdc++.h>
using namespace std;

const int MAX = 4e6 + 10;
const int INF = 1e9;

int IT[MAX][21];
int prv[MAX];
int a[MAX];
int n, q;

void build(int id, int l, int r){
	if (l == r){
		for (int i = 0; i <= 20; i++)
			IT[id][i] = 0;
		IT[id][__builtin_popcount(a[l])] = 1;
		return;
	}
	int m = (l+r) >> 1;
	build(id << 1, l, m);
	build(id << 1 ^ 1, m+1, r);
	for (int i = 0; i <= 20; i++)
		IT[id][i] = IT[id << 1][i] + IT[id << 1 ^ 1][i];
	prv[id] = 0;
}

void down(int id){
	if (!prv[id]) return;
	prv[id] = 0;
	int l = id << 1;
	int r = id << 1 ^ 1;
	for (int i = 0; i < 10; i++){
		swap(IT[l][i], IT[l][20-i]);
		swap(IT[r][i], IT[r][20-i]);
	}
	prv[l] ^= 1;
	prv[r] ^= 1;
}

void up(int id){
	int l = id << 1;
	int r = id << 1 ^ 1;
	for (int i = 0; i <= 20; i++)
		IT[id][i] = IT[l][i] + IT[r][i];
}

void update(int id, int l, int r, int lo, int hi){
	if (lo > r || hi < l) return;
	if (lo <= l && r <= hi){
		prv[id] ^= 1;
		for (int i = 0; i < 10; i++)
			swap(IT[id][i], IT[id][20-i]);
		return;
	}
	down(id);
	int m = (l + r) >> 1;
	update(id << 1, l, m, lo, hi);
	update(id << 1 ^ 1, m+1, r, lo, hi);
	up(id);
}

int query(int id, int l, int r, int lo, int hi, int val){
	if (lo > r || hi < l) return INF;
	if (lo <= l && r <= hi){
		if (!IT[id][val]) return INF;
		if (l == r)
			return l;
		down(id);
		int m = (l + r) >> 1;
		if (IT[id << 1][val])
			return query(id << 1, l, m, lo, hi, val);
		else
			return query(id << 1 ^ 1, m+1, r, lo, hi, val);
	}
	down(id);
	int m = (l + r) >> 1;
	int ret = query(id << 1, l, m, lo, hi, val);
	if (ret != INF)
		return ret;
	return query(id << 1 ^ 1, m+1, r, lo, hi, val);
}

int main(){
    #ifdef LOCAL_DEBUG
    	freopen("test.in", "rt", stdin);
    #endif
    ios::sync_with_stdio(false);

    int t;

    cin >> t;
	for (int cs = 1; cs <= t; cs ++){
		cout << "Case " << cs << ":\n";

		cin >> n >> q;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		build(1, 1, n);
		int type, l, r, v;
		while (q--){
			cin >> type >> l >> r;
			if (type == 1){
				cin >> v;
				v = __builtin_popcount(v);
				int res1 = INF, res2 = INF;
				int dist1 = INF, dist2 = INF;
				for (int i = v; i >= 0; i--)
					if ((res1 = query(1, 1, n, l, r, i)) != INF){
						dist1 = abs(v - i);
						break;
					}
			    for (int i = v; i <= 20; i++)
			    	if ((res2 = query(1, 1, n, l, r, i)) != INF){
			    		dist2 = abs(i - v);
			    		break;
			    	}
			    if (dist1 != dist2)
			    	cout << (dist1 < dist2 ? res1 : res2) << "\n";
			    else
			    	cout << min(res1, res2) << "\n";
			}
			else
				update(1, 1, n, l, r);
		}
    }

	return 0;
}