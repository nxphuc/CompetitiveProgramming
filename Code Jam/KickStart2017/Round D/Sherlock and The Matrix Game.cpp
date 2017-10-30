/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 1e6 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

typedef multiset<ll>::iterator m_iter;
typedef multiset<ll>::reverse_iterator m_riter;

int t, n, k, a1, b1, c, d, e1, e2, f;
int a[MAX], b[MAX];
int sRow, sCol;
multiset<int> row, col;
multiset<ll> mxSegRow, mnSegRow, mxSegCol, mnSegCol;
vector<ll> vec[4];
multiset<ll> res;

void update(int va, int vb){
	for (multiset<int>::iterator it = row.begin(); it != row.end(); it++){
		if (va < *it || (mxSegRow.size() >= k && va - *it < *mxSegRow.begin()))
			break;
		mxSegRow.insert(va - *it);
		if (mxSegRow.size() > k)
			mxSegRow.erase(mxSegRow.begin());
	}
	for (multiset<int>::reverse_iterator rit = row.rbegin(); rit != row.rend(); rit++){
		if (*rit <= va || (mnSegRow.size() >= k && va - *rit > *mnSegRow.rbegin()))
			break;
		mnSegRow.insert(va - *rit);
		if (mnSegRow.size() > k)
			mnSegRow.erase(--mnSegRow.end());
	}

	for (multiset<int>::iterator it = col.begin(); it != col.end(); it++){
		if (vb < *it || (mxSegCol.size() >= k && vb - *it < *mxSegCol.begin()))
			break;
		mxSegCol.insert(vb - *it);
		if (mxSegCol.size() > k)
			mxSegCol.erase(mxSegCol.begin());
	}
	for (multiset<int>::reverse_iterator rit = col.rbegin(); rit != col.rend(); rit++){
		if (*rit < vb || (mnSegCol.size() >= k && vb - *rit > *mnSegCol.rbegin()))
			break;
		mnSegCol.insert(vb - *rit);
		if (mnSegCol.size() > k)
			mnSegCol.erase(--mnSegRow.end());
	}
	row.insert(va);
	col.insert(vb);
}

void prepare(){
	int xn, x = a1;
	int yn, y = b1;
	int rn, r = 0;
	int sn, s = 0;

	row.clear();
	col.clear();
	mxSegRow.clear(); mnSegRow.clear();
	mxSegCol.clear(); mnSegCol.clear();
	sRow = a1;
	sCol = b1;

	row.insert(0); row.insert(a1);
	col.insert(0); col.insert(b1);
	if (a1 > 0)
		mxSegRow.insert(a1);
	else
		mnSegRow.insert(a1);
	if (b1 > 0)
		mxSegCol.insert(b1);
	else
		mnSegCol.insert(b1);

	for (int i = 2; i <= n; i++){
		xn = (c*x + d*y + e1) % f;
		yn = (c*y + d*x + e2) % f;
		rn = (c*r + d*s + e1) % 2;
		sn = (c*s + d*r + e2) % 2;

		a1 = rn ? -xn : xn;
		b1 = sn ? -yn : yn;
		sRow += a1;
		sCol += b1;
		update(sRow, sCol);

		x = xn, y = yn, r = rn, s = sn;
	}
}

void doMaxSegment(const vector<ll>& vecA, const vector<ll>& vecB){
	if (!vecA.size() || !vecB.size())
		return;

	priority_queue< pair<ll, pair<int,int> > > pq;
	int remain = k;
	int i, j;
	pair<ll, pair<int,int> > tmp;

	pq.push(make_pair(vecA[0]*vecB[0], make_pair(0, 0)));
	while (remain > 0 && pq.size()){
		tmp = pq.top();
		pq.pop();
		remain--;

		if (res.size() < k || tmp.first > *res.begin()){
			res.insert(tmp.first);
			if (res.size() > k) res.erase(res.begin());
		}

		i = tmp.second.first;
		j = tmp.second.second;
		if (i+1 < vecA.size())
			pq.push(make_pair(vecA[i+1]*vecB[j], make_pair(i+1, j)));
		if (j+1 < vecB.size())
			pq.push(make_pair(vecA[i]*vecB[j+1], make_pair(i, j+1)));
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
		// freopen("test.ou", "wt", stdout);
	#endif
	ios::sync_with_stdio(false);

	cin >> t;
	FOR(cs,1,t){
		cin >> n >> k >> a1 >> b1 >> c >> d >> e1 >> e2 >> f;

		prepare();
		res.clear();
		vec[0] = vector<ll>(mxSegRow.begin(), mxSegRow.end());
		vec[1] = vector<ll>(mnSegRow.begin(), mnSegRow.end());
		vec[2] = vector<ll>(mxSegCol.begin(), mxSegCol.end());
		vec[3] = vector<ll>(mnSegCol.begin(), mnSegCol.end());

		// for (int i = 0; i < 4; i++){
		// 	for (int e : vec[i])
		// 		cout << e << " ";
		// 	cout << "\n";
		// }

		reverse(vec[0].begin(), vec[0].end());
		reverse(vec[1].begin(), vec[1].end());
		
		doMaxSegment(vec[0], vec[2]);
		doMaxSegment(vec[1], vec[3]);
		if (res.size() < k){
			reverse(vec[0].begin(), vec[0].end());
			reverse(vec[1].begin(), vec[1].end());
			reverse(vec[2].begin(), vec[2].end());
			reverse(vec[3].begin(), vec[3].end());
			doMaxSegment(vec[0], vec[3]);
			doMaxSegment(vec[1], vec[2]);
		}

		cout << *res.begin() << "\n";
	}

	return 0;
}