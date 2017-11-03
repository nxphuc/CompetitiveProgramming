const int BASE = 10000; typedef vector <int> BigInt;

BigInt operator * (const BigInt a, const int mul) {
    BigInt c; int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        carry += a[i] * mul;
        c.push_back(carry % BASE);
        carry /= BASE;
    }
    if (carry) c.push_back(carry);
    return c;
}

BigInt operator * (const BigInt a, const BigInt b) {
    BigInt c(a.size() + b.size() + 5, 0);
    for (int i = 0; i < a.size(); i++) {
        int carry = 0;
        for (int j = 0; j < b.size(); j++) {
            int k = i + j; c[k] += a[i] * b[j] + carry;
            carry = c[k] / BASE; c[k] %= BASE;
        }
        if (carry) c[i + b.size()] += carry;
    }
    while (*c.rbegin() == 0 && c.size() > 1) c.pop_back();
    return c;
}

BigInt operator / (const BigInt a, const BigInt b) {
    BigInt c, t;
    for (int i = a.size() - 1; i >= 0; i--) {
        t.insert(t.begin(), a[i]); int lo = 1, hi = BASE - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (t < (b * mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        c.insert(c.begin(), hi); t = t - (b * hi);
    }
    while (*c.rbegin() == 0 && c.size() > 1) c.pop_back();
    return c;
}

BigInt operator % (const BigInt a, const BigInt b) {
    BigInt t;
    for (int i = a.size() - 1; i >= 0; i--) {
        t.insert(t.begin(), a[i]);
        int lo = 1, hi = BASE - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (t < (b * mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        t = t - (b * hi);
    }
    return t;
}
