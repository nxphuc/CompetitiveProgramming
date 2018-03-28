import heapq

def solve():
    min_queue = []
    max_queue = []
    query = int(input())
    size = 0
    while query:
        line = list(map(int, input().split()))
        if line[0] == 1:
            val = line[1]
            size += 1
            if size % 3 != 0 and size > 3:
                top = min_queue[0]
                if val > top:
                    heapq.heappush(min_queue, val)
                    heapq.heappush(max_queue, -heapq.heappop(min_queue))
                else:
                    heapq.heappush(max_queue, -val)
            else:
                heapq.heappush(max_queue, -val)
                while len(min_queue) < int(size / 3):
                    heapq.heappush(min_queue, -heapq.heappop(max_queue))
        else:
            if len(min_queue) == 0:
                print("No reviews yet")
            else:
                print(min_queue[0])
        query -= 1


if __name__ == '__main__':
    solve()
