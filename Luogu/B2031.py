a, b, c, d, e, f = list(map(float, input().split()))
print("%.2lf" % (((c - a) * (f - b) - (e - a) * (d - b)) / 2))
