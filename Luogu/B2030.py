import math
a, b = list(map(float, input().split()))
c, d = list(map(float, input().split()))
print("%.3lf" % math.sqrt(math.pow(a - c, 2) + math.pow(b - d, 2)))
