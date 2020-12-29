m = int(input())
n = int(input())
if n == 1:
    print(m)
    exit(0)
s = 0
b = 1
c = 0
p = []
while m > 0:
    p += [m % n]
    m //= n
    c += 1
while c > 0:
    c -= 1
    S = s
    B = b
    s = min(S+p[c], B+n-p[c])
    b = min(S+p[c]+1, B+n-p[c]-1)
print(s)
