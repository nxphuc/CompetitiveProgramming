#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 300;
const int MOD = 1e9 + 7;
const int INF = 1 << 8;
const double pi = acos(-1.0);
const double EPS = 1e-6;

unordered_map<int, string> f;
unordered_map<int, int> ops;

inline int Not(int n) {
	bitset<8> tmp(n);
	return (~tmp).to_ulong();
}

inline int And(int a, int b) {
	bitset<8> tmp_a(a), tmp_b(b);
	return (tmp_a & tmp_b).to_ulong();
}

inline int Or(int a, int b) {
	bitset<8> tmp_a(a), tmp_b(b);
	return (tmp_a | tmp_b).to_ulong();
}

struct Expres {
	int val;
	string expres;
	int len;

	Expres(int val = -1, const string& expres = "", int len = 0)
		: val(val), expres(expres), len(len) {}

	bool operator<(const Expres& other) const {
		if (expres.length() != other.expres.length()) {
			return expres.length() > other.expres.length();
		}
		return expres > other.expres;
	}
};

string getRev(const string& s) {
	if (s.length() == 1) {
		return "!" + s;
	}
	return "!(" + s + ")";
}

int optimize(int val, const string&  expres) {
	// if (expres == "x|y" || expres == "y|x") {
	// 	cout << "$ " << val << " " << f[val] << " " << expres << "\n";
	// }
	if (f.find(val) == f.end() || f[val].length() > expres.length()) {
		// cout << "# " << f[val] << " " << expres << "\n";
		f[val] = expres;
		return 1;
	}
	if (f[val].length() == expres.length() && f[val] > expres) {
		// cout << "# " << f[val] << " " << expres << "\n";
		f[val] = expres;
		return 1;
	}
	return 0;
}

void prepare() {
	priority_queue<Expres> pq;

	f[15] = "x"; pq.push(Expres(15, "x")); ops[15] = -1;
	f[51] = "y"; pq.push(Expres(51, "y")); ops[51] = -1;
	f[85] = "z"; pq.push(Expres(85, "z")); ops[85] = -1;
	f[Not(15)] = "!x"; pq.push(Expres(Not(15), "!x")); ops[Not(15)] = 0;
	f[Not(51)] = "!y"; pq.push(Expres(Not(51), "!y")); ops[Not(51)] = 0;
	f[Not(85)] = "!z"; pq.push(Expres(Not(85), "!z")); ops[Not(85)] = 0;

	// for (auto ex : f) {
	// 	cout << ex.first << " " << ex.second << "\n";
	// }
	// cout << "===============\n";

	string rev, expres, lft, rht, new_exp;
	int val, other, new_val;
	int cnt = 0;
	while (!pq.empty()) {
		Expres tmp = pq.top();
		pq.pop();
		cnt++;
		val = tmp.val;
		expres = tmp.expres;
		if (f[val] != expres) {
			continue;
		}

		// cout << "@ " << val << " " << expres << " " << ops[val] << "\n";

		rev = getRev(expres);
		if (optimize(Not(val), rev)) {
			pq.push(Expres(Not(val), rev));
			ops[Not(val)] = 0;
		}

		vector<Expres> v;
		for (auto ex : f) {
			v.push_back(Expres(ex.first, ex.second));
		}
		for (auto ex : v) {
			other = ex.val;
			rht = ex.expres;
			if (other != val) {
				lft = expres;
				
				// Or
				new_val = Or(val, other);
				new_exp = min(lft + "|" + rht, rht + "|" + lft);
				if (optimize(new_val, new_exp)) {
					pq.push(Expres(new_val, new_exp));
					ops[new_val] = 2;
				}

				new_val = Or(Not(val), other);
				new_exp = min(getRev(lft) + "|" + rht, rht + "|" + getRev(lft));
				if (optimize(new_val, new_exp)) {
					pq.push(Expres(new_val, new_exp));
					ops[new_val] = 2;
				}
				new_val = Or(val, Not(other));
				new_exp = min(getRev(rht) + "|" + lft, lft + "|" + getRev(rht));
				if (optimize(new_val, new_exp)) {
					pq.push(Expres(new_val, new_exp));
					ops[new_val] = 2;
				}

				// And
				string tmp_lft = lft, tmp_rht = rht;
				if (ops[val] == 2) {
					tmp_lft = "(" + lft + ")";
				}
				if (ops[other] == 2) {
					tmp_rht = "(" + rht + ")";
				}

				new_val = And(Not(val), other);
				new_exp = min(getRev(lft) + "&" + tmp_rht, tmp_rht + "&" + getRev(lft));
				if (optimize(new_val, new_exp)) {
					pq.push(Expres(new_val, new_exp));
					ops[new_val] = 1;
				}
				new_val = And(val, Not(other));
				new_exp = min(getRev(rht) + "&" + tmp_lft, tmp_lft + "&" + getRev(rht));
				if (optimize(new_val, new_exp)) {
					pq.push(Expres(new_val, new_exp));
					ops[new_val] = 1;
				}

				new_exp = min(tmp_lft + "&" + tmp_rht, tmp_rht + "&" + tmp_lft);
				new_val = And(val, other);
				if (optimize(new_val, new_exp)) {
					pq.push(Expres(new_val, new_exp));
					ops[new_val] = 1;
				}
			}
		}
	}
	cerr << cnt << "\n";
}

inline int toShort(string s) {
	return bitset<8>(s).to_ulong();
}

int main(){
	freopen("test.in", "rt", stdin);
	// freopen("test.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	prepare();
	int n;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		cout << f[toShort(s)] << "\n";
	}

	return 0;
}