import math
import decimal
import numpy


class vector:
    def __init__(self, X, Y, P) -> None:
        self.x = X
        self.y = Y
        self.v = math.atan2(X, Y)
        self.p = P


def work(v: float) -> float:
    while v < 0:
        v += math.pi * 2
    while v > math.pi * 2:
        v -= math.pi * 2
    return min(v, math.pi * 2 - v)


def work1(v: decimal.Decimal) -> decimal.Decimal:
    while v < 0:
        v += decimal.Decimal(math.pi * 2)
    while v > math.pi * 2:
        v -= decimal.Decimal(math.pi * 2)
    return min(v, decimal.Decimal(math.pi * 2) - v)

numpy.arc

n = int(input())
a = list()
for i in range(0, n):
    s = input().split()
    a.append(vector(int(s[0]), int(s[1]), i + 1))

a.sort(key=lambda x: x.v)

ans = 0

for i in range(0, n):
    if work(a[i].v - a[(i + 1) % n].v) == work(a[ans].v - a[(ans + 1) % n].v):
        if work1(decimal.Decimal(math.atan2(a[i].x, a[i].y)-math.atan2(a[(i + 1) % n].x, a[(i + 1) % n].y))) < work1(decimal.Decimal(math.atan2(a[ans].x, a[ans].y)-math.atan2(a[(ans + 1) % n].x, a[(ans + 1) % n].y))):
            ans = i
    elif work(a[i].v - a[(i + 1) % n].v) < work(a[ans].v - a[(ans + 1) % n].v):
        ans = i

print(a[ans].p, a[(ans + 1) % n].p)
