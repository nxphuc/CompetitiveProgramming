if __name__ == "__main__":
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    count = [0 for i in range(100001)]
    num_distinct = 0
    r = 0
    while r < n:
        count[a[r]] += 1
        if count[a[r]] == 1:
            num_distinct += 1
        if num_distinct == k:
            break
        r += 1
    if num_distinct == k:
        l = 0
        while l < n:
            count[a[l]] -= 1
            if count[a[l]] == 0:
                break
            l += 1
        print(l+1, r+1)
    else:
        print(-1, -1)