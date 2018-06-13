def count3(n):
    cnt = 0
    while n % 3 == 0:
        cnt += 1
        n //= 3
    return cnt

n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    a[i] = [count3(a[i]), a[i]]
a.sort(key=lambda x: (-x[0], x[1]))
for x in a:
    print(x[1], end=' ')