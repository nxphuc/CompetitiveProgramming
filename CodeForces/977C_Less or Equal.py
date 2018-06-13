n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
if k == 0:
    print(-1 if a[0] == 1 else a[0] - 1)
elif k == n:
    print(a[n - 1])
else:
    print(a[k - 1] if a[k - 1] != a[k] else -1)