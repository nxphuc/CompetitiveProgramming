#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

const int MAX = 1e5 + 10;
const int INF = 1e9;

pair<int,int> a[MAX];
int minX[MAX], maxX[MAX];
int minY[MAX], maxY[MAX];
vector<int> listY[MAX];
long long BIT[MAX];
int n, nx, ny;

void compress(){
	vector<int> v;

	for (int i = 0; i < n; i++)
		v.push_back(a[i].first);
	sort(v.begin(), v.end());                      
	v.resize(unique(v.begin(), v.end()) - v.begin());
	assert(v[0] >= 0 && v[v.size()-1] <= INF);
	nx = v.size();
	for (int i = 0; i < n; i++)
		a[i].first = lower_bound(v.begin(), v.end(), a[i].first) - v.begin() + 1;

	v.clear();
	for (int i = 0; i < n; i++)
		v.push_back(a[i].second);
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	assert(v[0] >= 0 && v[v.size()-1] <= INF);
	ny = v.size();
	for (int i = 0; i < n; i++){
		a[i].second = lower_bound(v.begin(), v.end(), a[i].second) - v.begin() + 1;
		listY[a[i].first].push_back(a[i].second);
	}
}

void setBIT(int id, int val){
	while (id < MAX){
		BIT[id] += val;
		id += id & (-id);
	}
}

long long getBIT(int id){
	long long res = 0;
	while (id){
		res += BIT[id];
		id -= id & (-id);
	}
	return res;
}

int inline isInner(int x, int y){
	return minX[y] < x && x < maxX[y]
		&& minY[x] < y && y < maxY[x];
}

int main(){
	ios::sync_with_stdio(false);

	scanf("%d", &n);
	for (int x, y, i = 0; i < n; i++){
		scanf("%d%d", &x, &y);
		a[i] = make_pair(x,y);
		minX[i] = minY[i] = INF;
		maxX[i] = maxY[i] = -INF;
	}
	minX[n] = minY[n] = INF;
	maxX[n] = maxY[n] = -INF;
	compress();
	for (int i = 0; i < n; i++){
		minX[a[i].second] = min(minX[a[i].second], a[i].first);
		maxX[a[i].second] = max(maxX[a[i].second], a[i].first);
		minY[a[i].first] = min(minY[a[i].first], a[i].second);
		maxY[a[i].first] = max(maxY[a[i].first], a[i].second);
	}

	long long res = n;
	for (int i = 1; i <= nx; i++){
		if (!listY[i].size()) continue;
		for (int y, j = 0; j < listY[i].size(); j++){
			y = listY[i][j];
			if (maxX[y] == minX[y]) continue;
			if (i == maxX[y])
				setBIT(y, -1);
		}
		if (maxY[i] != minY[i])
			res += getBIT(maxY[i]-1) - getBIT(minY[i]);
		for (int y, j = 0; j < listY[i].size(); j++){
			y = listY[i][j];
			if (maxX[y] == minX[y]) continue;
			if (i == minX[y])
				setBIT(y, 1);
		}
	}
	for (int i = 0; i < n; i++)
		res -= isInner(a[i].first, a[i].second);
	printf("%lld", res);
	return 0;
}