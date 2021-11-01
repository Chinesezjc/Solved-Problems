import math
h, r = list(map(float, input().split()))
print(math.ceil(20000 / (math.pi * r * r * h)))
