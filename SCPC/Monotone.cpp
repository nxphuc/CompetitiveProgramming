#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

struct Point{
	int x, y;
	
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

int t, n, l, r;
Point p[MAX];

int isMonotone(){
	priority_queue< int, vector<int>, greater<int> > pq;
	l = 0;
	for (int i = 0; i < n; i++){
		pq.push(x);
		if (p[i].x < p[l].x)
			l = i;
	}
	r = (l + 1) % n;
	while ((r + 1) % n != l){
		if (pq.top() < min(p[l].x, p[r].x))
			return 0;
		pq.pop();
		if (p[l].x < p[r].x)
			l = (l - 1 + n) % n;
		else
			r = (r + 1) % n;
	}
	return 1;
}

int main(){
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> t;
	for (int cs = 1; cs <= t; cs++){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		cout << "Case #" << cs << "\n";
		cout << (isMonotone() ? "YES\n" : "NO\n");
	}

	return 0;
}