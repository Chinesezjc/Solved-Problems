l, r = list(map(int, input().split()))
s = 0
for i in range(l, r + 1):
    if i % 17 == 0:
        s = s + i
print(s)
