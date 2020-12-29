tmp = input().split()
n = int(tmp[0])
m = int(tmp[1])
to = []
inp = []
can = 0
ans = []
good = []
for i in range(0, n):
    to.append([])
    inp.append(0)
for i in range(0, m):
    tmp = input().split()
    a = int(tmp[0]) - 1
    b = int(tmp[1]) - 1
    to[a].append(b)
for i in range(0, n):
    good.append(False)
    if (i == 0 or inp[i] > 0):
        good[i] = True
        for j in to[i]:
            inp[j] += 1
for i in range(0, n):
    
print(ans.__len__())
for i in ans:
    print(i + 1, end=' ')
