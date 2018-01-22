if __name__ == "__main__":
    t = int(input())

    for cs in range(t):
        n = int(input())
        c = list(map(int, input().split()))
        w = list(map(int, input().split()))
        found = [False for i in range(n)]
        max_sum = 0
        unique_sum = 0
        i = 0
        for j in range(n):
            if found[c[j]]:
                while c[i] != c[j]:
                    found[c[i]] = False
                    unique_sum -= w[i]
                    i += 1
                # do not need to set found[c[i]] = False
                unique_sum -= w[i]
                i += 1
            found[c[j]] = True
            unique_sum += w[j]
            max_sum = max(max_sum, unique_sum)
        print(max_sum)