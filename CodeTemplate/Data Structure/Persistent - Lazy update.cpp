// Persistent tree
item f[N * 20]; // remember N * log N+

void build(int l = 1, int r = n, int pos = 1) {
    if (l == r) {
        f[pos].sum = a[l];
        f[pos].left = a[l];
        f[pos].right = a[l];
        f[pos].max = a[l];
        f[pos].child_left = 0;
        f[pos].child_right = 0;
    }
    else {
        int m = l + r >> 1;
        int left = ++cnt;
        int right = ++cnt;
        build(l, m, left);
        build(m + 1, r, right);
        f[pos].max = max(max(f[left].max, f[right].max), f[left].right + f[right].left);
        f[pos].sum = f[left].sum + f[right].sum;
        f[pos].left = max(f[left].left, f[right].left + f[left].sum);
        f[pos].right = max(f[right].right, f[left].right + f[right].sum);
        f[pos].child_left = left;
        f[pos].child_right = right;
    }
}

void update(int x, int l, int r, int pos, int old) {
    if (l == r && l == x) {
        f[pos].sum = a[l];
        f[pos].left = a[l];
        f[pos].right = a[l];
        f[pos].max = a[l];
        f[pos].child_left = 0;
        f[pos].child_right = 0;
    }
    else {
        int m = l + r >> 1;
        int left, right;
        if (m >= x) {
            left = ++cnt;
            right = f[old].child_right;
            update(x, l, m, left, f[old].child_left);
        }
        else {
            left = f[old].child_left;
            right = ++cnt;
            update(x, m + 1, r, right, f[old].child_right);
        }
        f[pos].max = max(max(f[left].max, f[right].max), f[left].right + f[right].left);
        f[pos].sum = f[left].sum + f[right].sum;
        f[pos].left = max(f[left].left, f[right].left + f[left].sum);
        f[pos].right = max(f[right].right, f[left].right + f[right].sum);
        f[pos].child_left = left;
        f[pos].child_right = right;
    }
}

item query(int u, int v, int l, int r, int pos) {
    if (l > v || r < u) {
        item ret;
        ret.sum = ret.left = ret.right = ret.max = -INF;
        return ret;
    }
    if (l >= u && r <= v) {
        return f[pos];
    }
    else {
        int m = l + r >> 1;
        item ret1 = query(u, v, l, m, f[pos].child_left);
        item ret2 = query(u, v, m + 1, r, f[pos].child_right);
        item ret;
        ret.max = max(max(ret1.max, ret2.max), ret1.right + ret2.left);
        ret.sum = ret1.sum + ret2.sum;
        ret.left = max(ret1.left, ret2.left + ret1.sum);
        ret.right = max(ret2.right, ret1.right + ret2.sum);
        return ret;
    }
}

// Lazy update sum range
void update(int val, int start, int end, int l, int r, int pos) {
    if (lazy[pos] != 0) {
        f[pos] += (r - l + 1) * lazy[pos];
        if (l != r) {
            lazy[pos << 1] += lazy[pos];
            lazy[(pos << 1) + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (l > end || r < start) return;
    if (start >= l && end <= r) {
        f[pos] += (r - l + 1) * val;
        if (l != r) {
            lazy[pos << 1] += val;
            lazy[(pos << 1) + 1] += val;
        }
        return;
    }
    int m = l + r >> 1;
    update(val, start, end, l, m, pos << 1);
    update(val, start, end, m + 1, r, (pos << 1) + 1);
    f[pos] = f[pos << 1] + f[(pos << 1) + 1];
} 

int query(int start, int end, int l, int r, int pos) {
    if (r < start || l > end) return 0;
    if (lazy[pos] != 0) {
        f[pos] += (r - l + 1) * lazy[pos];
        if (l != r) {
            lazy[pos << 1] += lazy[pos];
            lazy[(pos << 1) + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (l <= start && r <= end) return f[pos];
    int m = l + r >> 1;
    int ret1 = query(start, end, l, m, pos << 1);
    int ret2 = query(start, end, m + 1, r, (pos << 1) + 1);
    return ret1 + ret2;
}