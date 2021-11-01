import math
a, b = input().split()
a = int(a)
print(8 + math.ceil(max(0, a - 1000) / 500) * 4 + (5 if b == 'y' else 0))
