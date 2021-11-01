n = int(input())
a, b, c = 0, 0, 0
for i in range(0, n):
    aa, bb, cc = list(map(int, input().split()))
    a, b, c = a + aa, b + bb, c + cc
print(a, b, c, a + b + c)
