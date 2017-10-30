#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("test.in", "rt", stdin);
	#endif

	int t, n;
	long long x, res, numPos, sumPos, sumNeg;
	vector<long long> neg, pos;

	cin >> t;
	while (t--){
		cin >> n;
		neg.clear();
		numPos = sumPos = sumNeg = 0;
		while (n--){
			cin >> x;
			if (x < 0){
				neg.push_back(x);
				sumNeg += x;
			}
			else{
				numPos++;
				sumPos += x;
			}
		}
		res = numPos*sumPos + sumNeg;
		sort(neg.begin(), neg.end(), greater<long long>());
		for (int x: neg){
			sumNeg -= x;
			sumPos += x;
			numPos++;
			res = max(res, numPos*sumPos + sumNeg);
		}
		cout << res << "\n";
	}

	return 0;
}