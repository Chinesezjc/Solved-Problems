x, a, y, b = input().split()
x, a, y, b = float(x), float(a), float(y), float(b)
print("%.2f" % ((b * y - a * x) / (b - a)))
