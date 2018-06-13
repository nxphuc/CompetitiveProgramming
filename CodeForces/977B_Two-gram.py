n = int(input())
s = input()
cur_max = 0
res = ""
for i in range(0, n - 1):
    cnt = 0
    for j in range(0, n - 1):
        if s[i: i + 2] == s[j: j + 2]:
            cnt += 1
    if cnt > cur_max:
        cur_max = cnt
        res = s[i: i + 2]
print(res)