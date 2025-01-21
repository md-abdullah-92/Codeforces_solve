import math
from sys import stdin, stdout
from collections import defaultdict

def distance(x1, y1, x2, y2):
    """Calculate Euclidean distance."""
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1

def solve():
    input = stdin.read
    data = input().split()
    idx = 0

    t = int(data[idx])
    idx += 1

    results = []
    for _ in range(t):
        n = int(data[idx])
        idx += 1

        circles = []
        for _ in range(n):
            x, y = map(int, data[idx:idx + 2])
            circles.append((x, y))
            idx += 2

        xs, ys, xt, yt = map(int, data[idx:idx + 4])
        idx += 4

        # Add start and goal as extra nodes
        nodes = circles + [(xs, ys), (xt, yt)]
        start_idx = n
        goal_idx = n + 1

        # Union-Find
        uf = UnionFind(len(nodes))

        # Connect circles based on distance
        for i in range(len(nodes)):
            for j in range(i + 1, len(nodes)):
                x1, y1 = nodes[i]
                x2, y2 = nodes[j]
                d = distance(x1, y1, x2, y2)
                if i < n and j < n:
                    # Circle-circle connection
                    if d <= 2:
                        uf.union(i, j)
                elif i >= n or j >= n:
                    # Point-circle connection
                    if d <= 1:
                        uf.union(i, j)

        # Check if start and goal are connected
        if uf.find(start_idx) == uf.find(goal_idx):
            results.append("NO")
        else:
            results.append("YES")

    stdout.write("\n".join(results) + "\n")
