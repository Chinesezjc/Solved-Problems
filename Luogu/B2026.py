import math
s = input().split()
print("%.10lf" % math.fmod(float(s[0]), float(s[1])))
