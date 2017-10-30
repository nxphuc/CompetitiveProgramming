import queue

MAX = 1010
INF = int(1e9)

# khai báo class Node với id là tên đỉnh, dist là chi phí
# define operator __lt__ (less than) cho class, so sánh theo dist nhỏ hơn, dùng trong PriorityQueue
class Triad:
    source = 0
    target = 0
    weight = 0
    def __init__(self, source, target, weight):
        self.source = source
        self.target = target
        self.weight = weight

def BellmanFord(source, graph, dist):
    dist[source] = 0
    for i in range(1, n):
        for j in range(m):
            u = graph[j].source
            v = graph[j].target
            w = graph[j].weight
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                path[v] = u
    for i in range(m):
        u = graph[i].source
        v = graph[i].target
        w = graph[i].weight
        if dist[u] != INF and dist[u] + w < dist[v]:
            return False
    return True

if __name__ == '__main__':
    t = int(input())
    graph = [Triad(0, 0, 0) for i in range(MAX)]
    dist = [INF for i in range(MAX)]
    path = [-1 for i in range(MAX)]
    n, m, u, v, w = -1, -1, -1, -1, -1
    while t > 0:
        t -= 1
        n, m = map(int, input().split())
        for i in range(n):
            dist[i], path[i] = INF, -1
        for i in range(m):
            u, v, w = map(int, input().split())
            graph[i] = Triad(u, v, w)
        res = BellmanFord(0, graph, dist)
        if res == False:
            print("possible")
        else:
            print("not possible")