import sys

def solve():
    n, k = map(int, sys.stdin.readline().split())
    v = list(map(int, sys.stdin.readline().split()))
    pod = 1
    for i in v:
        pod *= i

    s = sys.stdin.readline().strip()
    l, r = 0, n - 1
    result = []
    num_L = s.count('L')  # Count the number of 'L' characters
    for c in s:
        result.append(str(pod % k))
        if c == 'L':
            pod = pod // v[l]
            l += 1
        else:
            pod = pod // v[r]
            r -= 1
    # Adjust l and r based on the number of 'L' characters
    l += num_L
    r -= (len(s) - num_L)
    
    sys.stdout.write(' '.join(result) + '\n')

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for _ in range(T):
        solve()
