#include <bits/stdc++.h>
using namespace std;

struct Game {
	int id;
	int rating;
	int max_rating;
	int min_rating;
	int is_rate;
	int time;

	Game(int id = 0, int rating = 0,
		int min_rating = 0, int max_rating = 0,
		int is_rate = 0, int time = 0)
		: id(id), rating(rating), min_rating(min_rating),
		  max_rating(max_rating), is_rate(is_rate), time(time) {}
};

int matched(Game a, Game b) {
	if (a.rating < b.min_rating || a.rating > b.max_rating) {
		return 0;
	}
	if (b.rating < a.min_rating || b.rating > a.max_rating) {
		return 0;
	}
	if (a.is_rate != b.is_rate) {
		return 0;
	}
	if (a.time != b.time) {
		return 0;
	}
	return 1;
}

int findPossibleMatch(list<Game>& games_list, Game game) {
	for (auto it = games_list.begin(); it != games_list.end(); it++) {
		if (matched(*it, game)) {
			cout << it->id << "\n";
			games_list.erase(it);
			return 1;
		}
	}
	cout << "wait\n";
	return 0;
}

int main() {
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int t, n;
	int r, mn, mx, tm;
	string c, is_rate;

	cin >> t;
	while (t--) {
		cin >> n;
		list<Game> random_list, white_list, black_list;
		for (int i = 1; i <= n; i++) {
			cin >> r >> mn >> mx >> tm >> is_rate >> c;
			Game game(i, r, mn, mx, is_rate == "rated", tm);
			if (c == "random") {
				if (!findPossibleMatch(random_list, game)) {
					random_list.push_back(game);
				}
			}
			else {
				if (c == "white") {
					if (!findPossibleMatch(black_list, game)) {
						white_list.push_back(game);
					}
				}
				else {
					if (!findPossibleMatch(white_list, game)) {
						black_list.push_back(game);
					}
				}
			}
		}
	}

	return 0;
}