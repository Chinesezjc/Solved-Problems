x = float(input())
if 0 <= x < 5:
    print("%.3lf" % (-x + 2.5))
elif 5 <= x < 10:
    print("%.3lf" % (2 - 1.5 * (x - 3) * (x - 3)))
else:
    print("%.3lf" % (x / 2 - 1.5))
