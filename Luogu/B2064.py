a = [0, 1, 1]
t = int(input())
for i in range(3, 31):
    a.append(a[i - 2] + a[i - 1])
for i in range(t):
    x = int(input())
    print(a[x])
