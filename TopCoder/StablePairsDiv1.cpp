/*
// BEGIN CUT HERE

PROBLEM STATEMENT

Consider the set of integers between 1 and n, inclusive, and two positive integers c and k.
You want to build an ordered list of k pairs 
(x1, y1),
(x2, y2),
...
(xk, yk)
such that the following conditions are met.

 1 ≤ xi < yi ≤ n for all i between 1 and k, inclusive.
 yi < xi+1 for all i between 1 and k-1, inclusive.
 (x(i+1) + y(i+1)) - (xi + yi) = c for all i between 1 and k-1, inclusive.

If a list of pairs satisfies all of the above conditions, the list is said to be stable.
For any fixed n, c, and k, a stable list of k pairs is said to be maximal
if its sum of elements (the sum of all 2k integers it contains) is the largest among all stable lists 
of k pairs.




For instance, consider n=5, c=4, and k=2.
There are two stable lists of pairs: one is [(1, 2), (3, 4)] and the other is [(2, 3), (4, 5)].
The latter is the only maximal stable list of pairs in this example as its sum is (2+3+4+5) = 14.




Given n, c, and k, find one maximal stable list of pairs, 
and return a vector <int> that describes the list.
Specifically, if 
(x1, y1),
(x2, y2),
...,
(xk, yk)
is your maximal stable list of pairs, you must return 
{
x1, y1,
x2, y2,
...,
xk, yk
}.



If there are many maximal stable lists of pairs, you may return any one of them. 
If no stable list of pairs with the desired properties exists, you must return an empty vector <int>.



DEFINITION
Class:StablePairsDiv1
Method:findMaxStablePairs
Parameters:int, int, int
Returns:vector <int>
Method signature:vector <int> findMaxStablePairs(int n, int c, int k)


CONSTRAINTS
-n will be between 1 and 100, inclusive.
-c will be between 1 and 100, inclusive.
-k will be between 1 and 100, inclusive.


EXAMPLES

0)
5
4
2

Returns: {2, 3, 4, 5 }

This example was described in the problem statement.


1)
4
4
2

Returns: {1, 2, 3, 4 }



2)
1
100
1

Returns: { }

When n=1, regardless of c and k, there is no way to build a pair. 


3)
3
100
1

Returns: {2, 3 }

With k=1 we are looking for stable lists that only contain a single pair of numbers. There are two stable lists: [(1, 2)] and [(2, 3)]. Obviously, the second one is the maximal one in this case.

4)
10
6
3

Returns: {2, 5, 6, 7, 9, 10 }



5)
12
7
3

Returns: {4, 5, 6, 10, 11, 12 }




// END CUT HERE
*/

#line 132 "StablePairsDiv1.cpp"
#include <bits/stdc++.h>
using namespace std;

class StablePairsDiv1 {
	public:
	int f[110][110][210];
	pair<int, int> path[110][110][210];

	// int dp(int remain, int prev_sum, int prev) {
	// 	if (!remain) {
	// 		return 0;
	// 	}
	// 	int &ret = f[remain][prev_sum][prev];
	// 	if (ret != -1) {
	// 		return ret;
	// 	}
	// 	if (remain )
	// }

	vector <int> findMaxStablePairs(int n, int c, int k) {
		memset(f, -1, sizeof(f));
		for (int i = 0; i < 110; i++) {
			for (int j = 0; j < 110; j++) {
				for (int k = 0; k < 210; k++) {
					f[i][j][k] = -1;
				}
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				f[1][i + j][j] = i + j;
			}
		}
		for (int step = 1; step < k; step++) {
			for (int prev_sum = 1; prev_sum < 2 * n; prev_sum++) {
				for (int prev = 1; prev <= n; prev++) {
					if (f[step][prev_sum][prev] != -1) {
						for (int next_i = prev + 1; next_i < n; next_i++) {
							int next_j = c + prev_sum - next_i;
							if (next_j > next_i && next_j <= n) {
								if (f[step + 1][next_i + next_j][next_j] < f[step][prev_sum][prev] + next_i + next_j) {
									f[step + 1][next_i + next_j][next_j] = f[step][prev_sum][prev] + next_i + next_j;
									path[step + 1][next_i + next_j][next_j] = make_pair(prev_sum, prev);
								}
							}							
						}
					}
				}
			}
		}

		int res = -1;
		pair<int, int> id = make_pair(-1, -1);
		for (int sum = 1; sum < 2 * n; sum++) {
			for (int j = 1; j <= n; j++) {
				if (j < sum && f[k][sum][j] > res) {
					id = make_pair(sum, j);
					res = f[k][sum][j];
				}
			}
		}
		cerr << res << " " << id.first << " " << id.second << "\n";
		vector<int> v;
		if (res != -1) {
			int sum, j;
			for (int step = k; step >= 1; step--) {
				sum = id.first;
				j = id.second;
				cerr << step << " " << sum << " " << j << "\n";
				v.push_back(j);
				v.push_back(sum - j);
				id = path[step][sum][j];
			}
			reverse(v.begin(), v.end());
		}
		
		return v;
	}
};
