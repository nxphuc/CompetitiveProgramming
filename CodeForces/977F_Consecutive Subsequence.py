n = int(input())
a = list(map(int, input().split()))
d = dict()
prev = [-1 for i in range(n + 1)]

res = [0, -1]
for i in range(n):
    cur = [1, i]
    x = a[i]
    if x - 1 in d:
        cur[0] = d[x - 1][0] + 1
        prev[i] = d[x - 1][1]
    if x in d:
        if (d[x][0] < cur[0]):
            d[x] = cur
        else:
            cur = d[x]
    else:
        d[x] = cur
    if cur[0] > res[0]:
        res = [cur[0], i]

print(res[0])
f = []
cur = res[1]
while (cur != -1):
    f.append(cur + 1)
    cur = prev[cur]
for x in reversed(f):
    print(x, end = ' ')