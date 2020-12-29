tmp = input().split()
n = int(tmp[0])
m = int(tmp[1])
num = []
for i in range(0, n+1):
    num.append(0)
for i in range(0, m):
    tmp = input().split()
    a = int(tmp[0])
    b = int(tmp[1])
    num[a-1] += 1
    num[b] -= 1
for i in range(1, n):
    num[i] += num[i - 1]
num = sorted(num)
print(num[n // 2-1+n % 2])
