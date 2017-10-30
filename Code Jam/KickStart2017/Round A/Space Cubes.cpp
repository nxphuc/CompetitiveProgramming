/*
Author: nxphuc
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

const int MAX = 2e3 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct Star
{
	int x, y, z, r;
};

int T, n;
Star a[MAX];
int mark[MAX];
int mnX, mxX, mnY, mxY, mnZ, mxZ;

int inCube(int x, int y, int z, int sz, int id){
	int l = a[id].x - a[id].r;
	int r = a[id].x + a[id].r;
	if (!(x <= l && r <= x+sz))
		return 0;

	l = a[id].y - a[id].r;
	r = a[id].y + a[id].r;
	if (!(y <= l && r <= y+sz))
		return 0;

	l = a[id].z - a[id].r;
	r = a[id].z + a[id].r;
	if (!(z <= l && r <= z+sz))
		return 0;
	return 1;
}

int canPut(int l){
	int mnX2, mxX2, mnY2, mxY2, mnZ2, mxZ2;
	int cnt;
	// minX + minY + minZ
	memset(mark, 0, sizeof(mark));
	cnt = 0;
	REP(i,0,n)
		if (inCube(mnX, mnY, mnZ, l, i)){
			mark[i] = 1;
			cnt++;
		}
	if (cnt == n)
		return 1;
	mnX2 = mnY2 = mnZ2 = inf;
	mxX2 = mxY2 = mxZ2 = -inf;
	REP(i,0,n)
		if (!mark[i]){
			mnX2 = min(mnX2, a[i].x - a[i].r);
			mnY2 = min(mnY2, a[i].y - a[i].r);
			mnZ2 = min(mnZ2, a[i].z - a[i].r);
			mxX2 = max(mxX2, a[i].x + a[i].r);
			mxY2 = max(mxY2, a[i].y + a[i].r);
			mxZ2 = max(mxZ2, a[i].z + a[i].r);
		}
	if (max(max(abs(mxX2 - mnX2), abs(mxY2 - mnY2)), abs(mxZ2 - mnZ2)) <= l)
		return 1;
	// minX + minY + maxZ
	memset(mark, 0, sizeof(mark));
	cnt = 0;
	REP(i,0,n)
		if (inCube(mnX, mnY, mxZ-l, l, i)){
			mark[i] = 1;
			cnt++;
		}
	if (cnt == n)
		return 1;
	mnX2 = mnY2 = mnZ2 = inf;
	mxX2 = mxY2 = mxZ2 = -inf;
	REP(i,0,n)
		if (!mark[i]){
			mnX2 = min(mnX2, a[i].x - a[i].r);
			mnY2 = min(mnY2, a[i].y - a[i].r);
			mnZ2 = min(mnZ2, a[i].z - a[i].r);
			mxX2 = max(mxX2, a[i].x + a[i].r);
			mxY2 = max(mxY2, a[i].y + a[i].r);
			mxZ2 = max(mxZ2, a[i].z + a[i].r);
		}
	if (max(max(abs(mxX2 - mnX2), abs(mxY2 - mnY2)), abs(mxZ2 - mnZ2)) <= l)
		return 1;
	// minX + maxY + minZ
	memset(mark, 0, sizeof(mark));
	cnt = 0;
	REP(i,0,n)
		if (inCube(mnX, mxY-l, mnZ, l, i)){
			mark[i] = 1;
			cnt++;
		}
	if (cnt == n)
		return 1;
	mnX2 = mnY2 = mnZ2 = inf;
	mxX2 = mxY2 = mxZ2 = -inf;
	REP(i,0,n)
		if (!mark[i]){
			mnX2 = min(mnX2, a[i].x - a[i].r);
			mnY2 = min(mnY2, a[i].y - a[i].r);
			mnZ2 = min(mnZ2, a[i].z - a[i].r);
			mxX2 = max(mxX2, a[i].x + a[i].r);
			mxY2 = max(mxY2, a[i].y + a[i].r);
			mxZ2 = max(mxZ2, a[i].z + a[i].r);
		}
	if (max(max(abs(mxX2 - mnX2), abs(mxY2 - mnY2)), abs(mxZ2 - mnZ2)) <= l)
		return 1;
	// minX + maxY + maxZ
	memset(mark, 0, sizeof(mark));
	cnt = 0;
	REP(i,0,n)
		if (inCube(mnX, mxY-l, mxZ-l, l, i)){
			mark[i] = 1;
			cnt++;
		}
	if (cnt == n)
		return 1;
	mnX2 = mnY2 = mnZ2 = inf;
	mxX2 = mxY2 = mxZ2 = -inf;
	REP(i,0,n)
		if (!mark[i]){
			mnX2 = min(mnX2, a[i].x - a[i].r);
			mnY2 = min(mnY2, a[i].y - a[i].r);
			mnZ2 = min(mnZ2, a[i].z - a[i].r);
			mxX2 = max(mxX2, a[i].x + a[i].r);
			mxY2 = max(mxY2, a[i].y + a[i].r);
			mxZ2 = max(mxZ2, a[i].z + a[i].r);
		}
	if (max(max(abs(mxX2 - mnX2), abs(mxY2 - mnY2)), abs(mxZ2 - mnZ2)) <= l)
		return 1;

	// maxX + minY + minZ
	memset(mark, 0, sizeof(mark));
	cnt = 0;
	REP(i,0,n)
		if (inCube(mxX-l, mnY, mnZ, l, i)){
			mark[i] = 1;
			cnt++;
		}
	if (cnt == n)
		return 1;
	mnX2 = mnY2 = mnZ2 = inf;
	mxX2 = mxY2 = mxZ2 = -inf;
	REP(i,0,n)
		if (!mark[i]){
			mnX2 = min(mnX2, a[i].x - a[i].r);
			mnY2 = min(mnY2, a[i].y - a[i].r);
			mnZ2 = min(mnZ2, a[i].z - a[i].r);
			mxX2 = max(mxX2, a[i].x + a[i].r);
			mxY2 = max(mxY2, a[i].y + a[i].r);
			mxZ2 = max(mxZ2, a[i].z + a[i].r);
		}
	if (max(max(abs(mxX2 - mnX2), abs(mxY2 - mnY2)), abs(mxZ2 - mnZ2)) <= l)
		return 1;
	// maxX + minY + maxZ
	memset(mark, 0, sizeof(mark));
	cnt = 0;
	REP(i,0,n)
		if (inCube(mxX-l, mnY, mxZ-l, l, i)){
			mark[i] = 1;
			cnt++;
		}
	if (cnt == n)
		return 1;
	mnX2 = mnY2 = mnZ2 = inf;
	mxX2 = mxY2 = mxZ2 = -inf;
	REP(i,0,n)
		if (!mark[i]){
			mnX2 = min(mnX2, a[i].x - a[i].r);
			mnY2 = min(mnY2, a[i].y - a[i].r);
			mnZ2 = min(mnZ2, a[i].z - a[i].r);
			mxX2 = max(mxX2, a[i].x + a[i].r);
			mxY2 = max(mxY2, a[i].y + a[i].r);
			mxZ2 = max(mxZ2, a[i].z + a[i].r);
		}
	if (max(max(abs(mxX2 - mnX2), abs(mxY2 - mnY2)), abs(mxZ2 - mnZ2)) <= l)
		return 1;
	// maxX + maxY + minZ
	memset(mark, 0, sizeof(mark));
	cnt = 0;
	REP(i,0,n)
		if (inCube(mxX-l, mxY-l, mnZ, l, i)){
			mark[i] = 1;
			cnt++;
		}
	if (cnt == n)
		return 1;
	mnX2 = mnY2 = mnZ2 = inf;
	mxX2 = mxY2 = mxZ2 = -inf;
	REP(i,0,n)
		if (!mark[i]){
			mnX2 = min(mnX2, a[i].x - a[i].r);
			mnY2 = min(mnY2, a[i].y - a[i].r);
			mnZ2 = min(mnZ2, a[i].z - a[i].r);
			mxX2 = max(mxX2, a[i].x + a[i].r);
			mxY2 = max(mxY2, a[i].y + a[i].r);
			mxZ2 = max(mxZ2, a[i].z + a[i].r);
		}
	if (max(max(abs(mxX2 - mnX2), abs(mxY2 - mnY2)), abs(mxZ2 - mnZ2)) <= l)
		return 1;
	// maxX + maxY + maxZ
	memset(mark, 0, sizeof(mark));
	cnt = 0;
	REP(i,0,n)
		if (inCube(mxX-l, mxY-l, mxZ-l, l, i)){
			mark[i] = 1;
			cnt++;
		}
	if (cnt == n)
		return 1;
	mnX2 = mnY2 = mnZ2 = inf;
	mxX2 = mxY2 = mxZ2 = -inf;
	REP(i,0,n)
		if (!mark[i]){
			mnX2 = min(mnX2, a[i].x - a[i].r);
			mnY2 = min(mnY2, a[i].y - a[i].r);
			mnZ2 = min(mnZ2, a[i].z - a[i].r);
			mxX2 = max(mxX2, a[i].x + a[i].r);
			mxY2 = max(mxY2, a[i].y + a[i].r);
			mxZ2 = max(mxZ2, a[i].z + a[i].r);
		}
	if (max(max(abs(mxX2 - mnX2), abs(mxY2 - mnY2)), abs(mxZ2 - mnZ2)) <= l)
		return 1;
	return 0;
}

int main(){
	freopen("C-large.in", "rt", stdin);
	freopen("C-large.ou", "wt", stdout);
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	cin >> T;
	FOR(cs,1,T){
		mnX = mnY = mnZ = inf;
		mxX = mxY = mxZ = -inf;
		cin >> n;
		REP(i,0,n){
			cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;
			mnX = min(mnX, a[i].x - a[i].r);
			mnY = min(mnY, a[i].y - a[i].r);
			mnZ = min(mnZ, a[i].z - a[i].r);
			mxX = max(mxX, a[i].x + a[i].r);
			mxY = max(mxY, a[i].y + a[i].r);
			mxZ = max(mxZ, a[i].z + a[i].r);
		}

		int lo = 1;
		int hi = 2*inf;
		int mi, res;

		while (lo <= hi){
			mi = (lo + hi)/2;
			if (canPut(mi)){
				res = mi;
				hi = mi-1;
			}
			else
				lo = mi+1;
		}

		if (n == 1)
			cout << "Case #" << cs << ": " << 2*a[0].r << "\n";
		else
			cout << "Case #" << cs << ": " << res << "\n";
	}

	return 0;
}
