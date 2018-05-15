/*
// BEGIN CUT HERE

PROBLEM STATEMENT
You want to make a lot of sandwiches.
However, you only have a limited amount of cheese.
The only piece of cheese you currently have is a rectangular block with dimensions A, B, and C.

You can cut the block of cheese into smaller pieces.
You are only allowed to cut as follows:

Each cut must divide one block of cheese into two smaller blocks of cheese.
Each cut must be parallel to one of the faces of the piece you are cutting.
Each of the two smaller blocks must have integer dimensions.


When placing a block of cheese onto a piece of bread, the cheese is always rotated so that its shortest side is vertical.
In other words, suppose you have a block of cheese with dimensions (X,Y,Z) such that X ≥ Y ≥ Z.
If you place this block onto a piece of bread, its surface area will be X*Y and its thickness will be Z.

A block of cheese is called a good slice if and only if its thickness is greater than or equal to S.
(Recall that the thickness of a block is the length of its shortest side.)

You can cut your block of cheese into arbitrarily many pieces, as long as you follow the rules given above.
Your goal is to cut the block in such a way that maximizes the total surface area of all good slices among the pieces.
Note that your way of cutting may also produce some pieces that are not good slices, but those pieces won't contribute to the surface area.
The number of good slices does not matter, we only care about their surface.
Different good slices may have different dimensions.

You are given the ints A, B, C, and S.
Return the maximum total surface area of good slices you can get.

DEFINITION
Class:CheeseSlicing
Method:totalArea
Parameters:int, int, int, int
Returns:int
Method signature:int totalArea(int A, int B, int C, int S)


CONSTRAINTS
-A, B and C will be between 1 and 100, inclusive.
-S will be between 1 and 10, inclusive.


EXAMPLES

0)
1
3
3
2

Returns: 0

One of the dimensions of this block is 1.
Regardless of how we cut it, each piece will have one dimension equal to 1.
As S=2, this means that producing a good slice is impossible.
Hence, the maximum total surface area of good slices is 0.

1)
5
3
5
3

Returns: 25

The entire block is a good slice with thickness 3 and surface area 5*5 = 25.
An optimal solution is to make no cuts and to simply take this one block.

2)
5
5
5
2

Returns: 58

One possible sequence of cuts:

 5x5x5 -> 2x5x5 + 3x5x5 
 3x5x5 -> 3x2x5 + 3x3x5 
 3x3x5 -> 3x3x2 + 3x3x3 

After these three cuts we have four pieces: 2x5x5, 3x2x5, 3x3x2, and 3x3x3.
Each of these is a good slice.
Their total surface area is 5*5 + 3*5 + 3*3 + 3*3.

3)
49
92
20
3

Returns: 30045




// END CUT HERE
*/

#line 105 "CheeseSlicing.cpp"
#include <bits/stdc++.h>
using namespace std;

class CheeseSlicing {
public:
	int f[110][110][110];

	int dp(int x, int y, int z, int s) {
		int a[3] = {x, y, z};
		sort(a, a + 3);
		x = a[2], y = a[1], z = a[0];

		if (f[x][y][z] != -1) {
			return f[x][y][z];
		}
		if (z < s) {
			return 0;
		}

		int &ret = f[x][y][z];
		ret = x*y;
		for (int i = s; i <= x - s; i++) {
			ret = max(ret, dp(i, y, z, s) + dp(x - i, y, z, s));
		}
		for (int i = s; i <= y - s; i++) {
			ret = max(ret, dp(x, i, z, s) + dp(x, y - i, z, s));
		}
		for (int i = s; i <= z - s; i++) {
			ret = max(ret, dp(x, y, i, s) + dp(x, y, z - i, s));
		}
		return ret;
	}

	int totalArea(int A, int B, int C, int S) {
		memset(f, -1, sizeof(f));
		return dp(A, B, C, S);
	}
};
