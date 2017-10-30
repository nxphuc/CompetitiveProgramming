#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int binarySearch(const vector<int>& a, int left, int right, int x)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (x == a[mid])
			return mid;
		else if (x < a[mid])
			right = mid - 1;
		else if (x > a[mid])
			left = mid + 1;
	}
	return -1;
}

int main(){
	int n, k, cnt = 0;
	vector<int> a;

	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(),a.end());
	for (int i = 0; i < n; i++)
		cnt += binarySearch(a, i+1, n-1, a[i] + k) >= 0;
	cout << cnt;

	return 0;
}