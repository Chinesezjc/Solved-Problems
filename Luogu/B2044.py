a = list(map(int, input().split()))
c = 0
for i in a:
    if i < 60:
        c = c+1
print(1 if c == 1 else 0)
