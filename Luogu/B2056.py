n = int(input())
s = 0
for i in range(0, n):
    s = s + int(input())
print(s, "%.5lf" % (s / n))
