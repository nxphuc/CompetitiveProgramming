#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int a, b, f, k;

	cin >> a >> b >> f >> k;
	if (b / a >= k) {
		cout << 0;
		return 0;
	}
	if (b < max(f, a - f)) {
		cout << -1;
		return 0;
	}

	int cnt = 0, res = 0;
	int cur_fuel = b;
	int next_pos, cur_pos = 0;
	int dist[4] = {f, a-f, a - f, f};
	while (1) {
		while (cur_fuel >= dist[cur_pos]) {
			cur_fuel -= dist[cur_pos];
			cur_pos = (cur_pos + 1) % 4;
			if (cur_pos % 2 == 0) {
				cnt++;
				if (cnt == k) {
					cout << res;
					return 0;
				}
			}
		}
		if (cur_pos % 2 == 0) {
			cur_pos = (cur_pos + 3) % 4;
			cnt--;
		}
		cur_fuel = b;
		if (cnt + 1 < k && cur_fuel < dist[cur_pos] + dist[(cur_pos + 1) % 4]) {
			cout << -1;
			return 0;
		}
		res++;
	}

	return 0;
}