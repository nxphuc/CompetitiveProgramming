import queue
n, m = map(int, input().split())
adj = [[] for i in range(n + 1)]
visited = [False for i in range(n + 1)]

def bfs(u):
    st = []
    st.append(u)
    flag = len(adj[u]) == 2
    while len(st) > 0:
        u = st[-1]
        st.pop()
        for v in adj[u]:
            if visited[v] == False:
                if len(adj[v]) != 2:
                    flag = False
                visited[v] = True
                st.append(v)
    return flag

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)
res = 0
for i in range(1, n + 1):
    if visited[i] == False:
        res += bfs(i) == True
print(res)
