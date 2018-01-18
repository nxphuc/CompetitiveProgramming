#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const double pi = acos(-1.0);
const double EPS = 1e-6;

int min_diff = INT_MAX;
int a_mask = -1, b_mask = -1;
int n, m;
int n_mask, m_mask;
vector<int> a, b;
map<int, int> state[4];

int getDiff(const vector<int> &a, int n, int mask) {
	int diff = 0;
	for (int i = 0; i < n; i++) {
		if (mask % 3 == 1) {
			diff += a[i];
		}
		else if (mask % 3 == 2) {
			diff -= a[i];
		}
		mask /= 3;
	}
	return diff;
}

int getState(const vector<int>& a, int mask) {
	int flag = 0;
	for (int i = 0; i < a.size(); i++) {
		if (mask % 3 == 1) {
			flag |= 1;
		}
		else if (mask % 3 == 2) {
			flag |= 2;
		}
		mask /= 3;
	}
	return flag;
}

void show(vector<int> a, int n, int mask, int key, int bonus) {
	for (int i = 0; i < n; i++) {
		if (mask % 3 == key) {
			cout << i+bonus << " ";
		}
		mask /= 3;
	}
}

void showResult() {
	show(a, n, a_mask, 1, 1);
	show(b, m, b_mask, 1, n+1);
	cout << "\n";
	show(a, n, a_mask, 2, 1);
	show(b, m, b_mask, 2, n+1);
}

void opt(int state_id, int diff, int mask) {
	auto it = state[state_id].lower_bound(diff);
	if (it != state[state_id].end()) {
		// cout << "@ " << (it->first) << " " << diff << " " << min_diff << "\n";
		if (abs((it->first) - diff) < min_diff) {
			a_mask = it->second;
			b_mask = mask;
			min_diff = abs((it->first) - diff);
		}
	}
	if (it != state[state_id].begin()) {
		it--;
		// cout << "! " << (it->first) << " " << diff << " " << min_diff << "\n";
		if (abs((it->first) - diff) < min_diff) {
			a_mask = it->second;
			b_mask = mask;
			min_diff = abs((it->first) - diff);
		}
	}
}

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	cin >> n;
	m = n >> 1;
	n -= m;
	n_mask = (int)pow(3, n);
	m_mask = (int)pow(3, m);
	for (int x, i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	for (int x, i = 0; i < m; i++) {
		cin >> x;
		b.push_back(x);
	}
	for (int i = 0; i < n_mask; i++) {
		state[getState(a, i)][getDiff(a, n, i)] = i;
	}
	// for (int i = 0; i < 4; i++) {
	// 	cout << "state " << i << "\n";
	// 	for (auto kvp : state[i]) {
	// 		cout << kvp.first << " - " << kvp.second << "\n";
	// 	}
	// }

	for (int i = 0; i < m_mask; i++) {
		int diff = -getDiff(b, m, i);
		// cout << "# " << i << " " << diff << " " << getState(b, i) << "\n";
		switch (getState(b, i)) {
			case 0:
				opt(state[3], diff, i);
				break;
			case 1:
				opt(state[2], diff, i);
				opt(state[3], diff, i);
				break;
			case 2:
				opt(state[1], diff, i);
				opt(state[3], diff, i);
				break;
			case 3:
				opt(state[1], diff, i);
				opt(state[2], diff, i);
				opt(state[3], diff, i);
				break;
		}
		if (min_diff == 0) {
			showResult();
			return 0;
		}
	}
	showResult();
	return 0;
}