#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;

int taken[MAX];
int n, k, bill;
int count_bill;
long long res;
priority_queue<pair<int, int> > max_heap;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_heap;

int main() {
    // freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> bill;
            count_bill++;

            max_heap.push(make_pair(bill, count_bill));
            min_heap.push(make_pair(bill, count_bill));
        }

        // trong khi hoa don lon nhat da bi xoa
        while (taken[max_heap.top().second] == 1) {
            max_heap.pop();
        }

        // trong khi hoa don nho nhat da bi xoa
        while (taken[min_heap.top().second] == 1) {
            min_heap.pop();
        }

        pair<int, int> max_bill = max_heap.top();
        pair<int, int> min_bill = min_heap.top();
        max_heap.pop();
        min_heap.pop();
        taken[max_bill.second] = 1;
        taken[min_bill.second] = 1;
        res += max_bill.first - min_bill.first;
    }
    cout << res;

    return 0;
}