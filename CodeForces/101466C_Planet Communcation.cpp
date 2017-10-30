#include <bits/stdc++.h>

using namespace std;

const int N = 10009;

struct coor {
	int x, y, z;
	coor () {}
	coor (int x, int y, int z) : x(x), y(y), z(z) {}
	coor (const coor &other) {
		x = other.x;
		y = other.y;
		z = other.z;
	}

	bool operator<(const coor& other) const{
		if (x != other.x) return x < other.x;
		if (y != other.y) return y < other.y;
		return z < other.z;
	}
	bool operator==(const coor& other) const{
		return x == other.x && y == other.y && z == other.z;
	}
} a[N];

bool func(coor i, coor j) {
	if (i.x == j.x) {
		if (i.y == j.y)
			return i.z < j.z;
		else
			return i.y < j.y;
	} else
	return i.x < j.x;
}

int GCD(int a, int b) {
	a = abs(a);
	b = abs(b);
	int r = b;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

vector<coor> v;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
	int m;
	if (n < 2){
		printf("0");
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		coor tmp = coor(a[1].x - a[i].x, a[1].y - a[i].y, a[1].z - a[i].z);
		m = GCD(tmp.x, tmp.y);
		m = GCD(m, tmp.z);
		tmp.x /= m;
		tmp.y /= m;
		tmp.z /= m;
		if (tmp.x < 0) {
			tmp.x *= -1;
			tmp.y *= -1;
			tmp.z *= -1;
		}
		else{
			if (tmp.x == 0){
				if (tmp.y < 0){
					tmp.y *= -1;
					tmp.z *= -1;
				}
				else{
					if (tmp.y == 0){
						if (tmp.z < 0)
							tmp.z *= -1;
					}
				}
			}
		}
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	printf("%d", v.size());
}