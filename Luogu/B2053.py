import math
a, b, c = list(map(float, input().split()))
a, b, c = a / a, b / a, c / a
delta = b * b - 4 * a * c
if delta < 0:
    print("No answer!")
elif delta == 0:
    print("x1=x2=%.5lf" % (-b/(2*a)))
else:
    print("x1=%.5lf;x2=%.5lf" %
          (((-b - math.sqrt(delta))/(2*a)), ((-b + math.sqrt(delta))/(2*a))))
