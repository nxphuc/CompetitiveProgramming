if __name__ == "__main__":
    n, d = map(int, input().split())
    a = list(map(int, input().split()))
    num_ways = 0
    j = 0
    for i in range(n):
        while j < n and a[j] - a[i] <= d:
            j += 1
        num = j - i # we have num elements from i to j-1
        num_ways += (num - 1) * (num - 2) // 2
    print(num_ways)