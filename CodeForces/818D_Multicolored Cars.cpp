#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;

int cnt[MAX];
int n, x, a, cntA;
priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;
pair<int,int> tmp;

int main(){
	#ifdef LOCAL_DEBUG
		freopen("test.in", "rt", stdin);
	#endif
	ios::sync_with_stdio(false);

	for (int i = 1; i < MAX; i++) pq.push(make_pair(0, i));
	cin >> n >> a;
	while (n--){
		cin >> x;
		if (x == a){
			cntA++;
			while (pq.size()){
				tmp = pq.top();
				if (tmp.first >= cntA)
					break;
				pq.pop();
				if (tmp.first == cnt[tmp.second])
					cnt[tmp.second] = -1;
			}
		}
		else{
			if (cnt[x] != -1){
				cnt[x]++;
				pq.push(make_pair(cnt[x], x));
			}
		}
	}
	for (x = 1; x < MAX; x++)
		if (x != a && cnt[x] >= cntA){
			cout << x;
			return 0;
		}
	cout << -1;

	return 0;
}