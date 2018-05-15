/*
// BEGIN CUT HERE

PROBLEM STATEMENT

You are given a set of colored points on a straight line.



You play a game with these points.
The game is a sequence of moves.
In each move you have to erase two points that are adjacent and share the same color.
(Two points are adjacent if there is no other point between them. Distances don't matter.)



You are given the string points. Each character of points describes the color of one point, in the order in which they are arranged on the line at the beginning of the game.
(Different letters represent different colors.)
Compute and return the maximum number of moves you can make.


DEFINITION
Class:LineOff
Method:movesToDo
Parameters:string
Returns:int
Method signature:int movesToDo(string points)


CONSTRAINTS
-points will contain between 1 and 50 characters, inclusive.
-Each character in points will be a lowercase English letter ('a'-'z').


EXAMPLES

0)
"abba"

Returns: 2

The only valid first move is to erase the two points of color 'b'. After that move the points of color 'a' are now adjacent and they can be removed in our second move.

1)
"zwwwzffw"

Returns: 2

You can remove two 'w' points and two 'f' points with your first two moves. After that the remaining points on the line will be arranged as follows: "zwzw". In this situation you don't have any adjacent points that share the same color, so there are no more moves.

2)
"rrrrrrr"

Returns: 3

With an odd number of points, at least one of them will have no pair.

3)
"dfghj"

Returns: 0

All colors are different so no points can be removed.

4)
"wasitacarooracatisaw"

Returns: 10




// END CUT HERE
*/

#line 77 "LineOff.cpp"
#include <bits/stdc++.h>
using namespace std;

class LineOff {
	public:
	int movesToDo(string points) {
		int n = points.length();
		int flag = 1;
		int res = 0;

		while (flag) {
			flag = 0;
			for (int i = 0; i < n - 1; i++) {
				if (points[i] == points[i + 1]) {
					points.erase(i, 2);
					flag = 1;
					n -= 2;
					res++;
					break;
				}
			}
		}
		return res;
	}
};
