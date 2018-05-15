/*
// BEGIN CUT HERE

PROBLEM STATEMENT

A string is called a block if it consists of exactly three equal letters.

A string is called a one-block string if it contains exactly one contiguous substring that is a block.

For example:

"aaa" and "abcccdd" are one-block strings
"noblocks" and "ababab" are not one-block strings, as they do not contain any blocks
"xxxyyyzzz" and "baaaad" are not one-block strings, as each of them contains at least two blocks

Note that the two blocks in "baaaad" overlap partially.

You are given the ints L and S.
If we can only use the first S lowercase letters of the English alphabet, how many different one-block strings of length L are there?
Return their count modulo 10^9 + 7.

DEFINITION
Class:ThreeSameLetters
Method:countStrings
Parameters:int, int
Returns:int
Method signature:int countStrings(int L, int S)


CONSTRAINTS
-L will be between 1 and 26, inclusive.
-S will be between 1 and 26, inclusive.


EXAMPLES

0)
3
7

Returns: 7

The seven one-block strings are "aaa", "bbb", "ccc", ..., "ggg".

1)
4
2

Returns: 4

The four one-block strings are "aaab", "abbb", "baaa", and "bbba".

2)
2
17

Returns: 0



3)
10
11

Returns: 410199993

Don't forget to do the calculations modulo 10^9 + 7.


// END CUT HERE
*/

#line 85 "ThreeSameLetters.cpp"
#include <bits/stdc++.h>
using namespace std;

class ThreeSameLetters {
	public:
	long long MOD = 1000000007;
	long long f[30];

	long long calc(int n, long long S) {
		if (!n) {
			return 1;
		}
		if (n == 1) {
			return S - 1;
		}
		if (n == 2) {
			return (S * (S - 1)) % MOD;
		}
		return f[n];
	}

	int countStrings(int L, int S) {
		f[0] = 1;
		f[1] = S;
		f[2] = (S * S) % MOD;
		for (int i = 3; i <= L; i++) {
			f[i] = ((f[i - 1] + f[i - 2]) * (S - 1LL)) % MOD;
		}
		long long res = 0;
		for (int i = 0; i < L; i++) {
			if (L - i - 3 < 0) {
				break;
			}
			res = (res + ((calc(i, S) * calc(L - i - 3, S)) % MOD)) % MOD;
		}
		return (res * S) % MOD;
	}
};
