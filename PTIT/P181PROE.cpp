#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int INF = 1e9;

struct Node {
    int lazy; // giá trị T trong phân tích trên
    int val; // giá trị lớn nhất.
    int id;
} nodes[MAX * 4];

void down(int id) {
    int t = nodes[id].lazy;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t;

    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t;

    nodes[id].lazy = 0;
}

void build(int id, int l, int r) {
    if (l == r) {
        nodes[id].lazy = 0;
        nodes[id].val = 0;
        nodes[id].id = l;
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        // Khi cài đặt, ta LUÔN ĐẢM BẢO giá trị của nút được cập nhật ĐỒNG THỜI với
        // giá trị lazy propagation. Như vậy sẽ tránh sai sót.
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    down(id); // đẩy giá trị lazy propagation xuống các con

    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    if (nodes[id*2].val >= nodes[id*2+1].val) {
        nodes[id].val = nodes[id * 2].val;
        nodes[id].id = nodes[id * 2].id;
    }
    else {
        nodes[id].val = nodes[id * 2 + 1].val;
        nodes[id].id = nodes[id * 2 + 1].id;
    }
    // nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
}

pair<int, int> get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return make_pair(-INF, -1);
    }
    if (u <= l && r <= v) {
        return make_pair(nodes[id].val, nodes[id].id);
    }
    int mid = (l + r) / 2;
    down(id); // đẩy giá trị lazy propagation xuống các con

    pair<int, int> lft = get(id*2, l, mid, u, v);
    pair<int, int> rht = get(id*2+1, mid+1, r, u, v);
    if (rht.first > lft.first) {
        return rht;
    }
    else {
        return lft;
    }
    // return max(get(id*2, l, mid, u, v),
    //     get(id*2+1, mid+1, r, u, v));
    // Trong các bài toán tổng quát, giá trị ở nút id có thể bị thay đổi (do ta đẩy lazy propagation
    // xuống các con). Khi đó, ta cần cập nhật lại thông tin của nút id dựa trên thông tin của các con.
}

int main() {
    freopen("test.in", "rt", stdin);
    ios::sync_with_stdio(false);

    int n, l, r;
    
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> l >> r;
    for (int cur_l, cur_r, i = 0; i < n; i++) {
        cur_l = l + i;
        cur_r = r + i - 1;
        if (cur_l > n) {
            cur_l -= n;
        }
        if (cur_r > n) {
            cur_r -= n;
        }
        cout << cur_l << " " << cur_r << "\n";
        if (cur_l <= cur_r) {
            update(1, 1, n, cur_l, cur_r, a[i]);
        }
        else {
            update(1, 1, n, 1, cur_r, a[i]);
            update(1, 1, n, cur_l, n, a[i]);
        }
    }
    pair<int,int> res = get(1, 1, n, 1, n);
    cout << res.first << " " << res.second << "\n";

    return 0;
}
