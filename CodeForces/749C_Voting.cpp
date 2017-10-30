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

const int MAX = 1e6 + 10;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n;
	string s;
	list<int> listD, listR;

	cin >> n;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == 'D')
			listD.push_back(i);
		else
			listR.push_back(i);
	list<int>::iterator iR, iD;
	while (listD.size() && listR.size()){
		iR = listR.begin();
		iD = listD.begin();
		while (iR != listR.end() && iD != listD.end()){
			if (*iD < *iR){
				iR = listR.erase(iR);
				iD++;
			}
			else{
				iD = listD.erase(iD);
				iR++;
			}
		}
		while (iR != listR.end() && listD.size() > 0){
			iR++;
			listD.erase(listD.begin());
		}
		while (iD != listD.end() && listR.size() > 0){
			iD++;
			listR.erase(listR.begin());
		}
	}
	cout << (listD.size() ? "D" : "R");

	return 0;
}
