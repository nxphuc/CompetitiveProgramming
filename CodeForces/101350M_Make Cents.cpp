#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);

	int t;
	int n, m;
	double res = 0;
	char s[15];
	double v;
	map<string, double> mymap;

	scanf("%d", &t);
	while (t--){
		res = 0;
		mymap["JD"] = 1.0;
		scanf("%d%d", &n, &m);
		printf("%d %d", n, m);
		while (n--){
			scanf("%s%lf", &s, &v);
			printf("%s %lf\n", s, v);
			mymap[s] = v;
		}
		while (m--){
			scanf("%lf%s", &v, &s);
			// printf("%lf %lf %s %lf\n", res, v, s, mymap[s]);
			res += v*mymap[s];
		}
		printf("%.6lf\n", res);
	}

	return 0;
}