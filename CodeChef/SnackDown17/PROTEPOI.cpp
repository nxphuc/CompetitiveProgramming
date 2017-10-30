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

const int MAX = 1e5 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

struct Segment{
	pair<int,int> head, tail;
};

int n, m, k;
int lower, upper;
int points[MAX];
vector< pair<int,int> > row, col;

// Hàm kiểm tra điểm nằm trong hình chữ nhật
int pointInRectangle(int top, int left, int bot, int right, const pair<int,int>& p){
	return top <= p.first && p.first <= bot
		&& left <= p.second && p.second <= right;
}

// Hàm kiểm tra đoạn thẳng nằm trong hình chữ nhật.
// Một đoạn thẳng nằm trong hình chữ nhật nếu cả 2 điểm mút của nó đều nằm trong HCN
int segmentInRectangle(int top, int left, int bot, int right, const Segment& s){
	return pointInRectangle(top, left, bot, right, s.head)
		&& pointInRectangle(top, left, bot, right, s.tail);
}

// Hàm kiểm tra đoạn thẳng s có nằm ở 1 trong 4 góc hình vuông hay không
int inCorner(const Segment& s){
	return segmentInRectangle(1, 1, lower, lower, s)
		|| segmentInRectangle(1, upper, lower, n, s)
		|| segmentInRectangle(upper, 1, n, lower, s)
		|| segmentInRectangle(upper, upper, n, n, s);
}

// Hàm kiểm tra đoạn thẳng s có thuộc hình chữ nhật phía trên hoặc dưới hình vuông K*K hay không
// Tức kiểm tra s có thuộc hình (SQ1, RECT1, SQ2) hoặc (SQ3, RECT2, SQ4) hay không.
int inTopBot(const Segment& s){
	return segmentInRectangle(1, 1, lower, n, s)
		|| segmentInRectangle(upper, 1, n, n, s);
}

int solve(vector< pair<int,int> > v){
	int endPoint = lower;
	int maxEnd;
	int i = 0;
	int res = 0;

	sort(v.begin(), v.end());
	while (i < v.size()){
		if (endPoint+1 < v[i].first)
			return -1;
		maxEnd = v[i].second;
		while (i < v.size() && endPoint+1 >= v[i].first){
			maxEnd = max(maxEnd, v[i].second);
			i++;
		}
		res++;
		endPoint = maxEnd;
		if (endPoint + 1 >= upper)
			return res;
	}
	return -1;
}

int main(){
	// freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	Segment tmp;
	int t;

	cin >> t;
	while (t--){
		cin >> n >> k >> m;

		lower = (n - k)/2;			// lower chính là L-1
		upper = k + lower + 1;		// upper là R+1
		row.clear();
		col.clear();

		REP(i,0,m){
			cin >> tmp.head.first >> tmp.head.second >> tmp.tail.first >> tmp.tail.second;
			if (tmp.head > tmp.tail) swap(tmp.head, tmp.tail);
			if (!inCorner(tmp)){
				if (inTopBot(tmp))
					row.push_back(make_pair(tmp.head.second, tmp.tail.second));
				else
					col.push_back(make_pair(tmp.head.first, tmp.tail.first));
			}
		}

		int resRow = solve(row);
		int resCol = solve(col);
		cout << (resCol < 0 || resRow < 0 ? -1 : resCol + resRow) << "\n";
	}

	return 0;
}