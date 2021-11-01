a = list(map(int, input().split()))
a.sort()
print(1 if a[0]+a[1] > a[2] else 0)
