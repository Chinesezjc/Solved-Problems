n = int(input())
s = input().split()
x = int(s[1]) / int(s[0])
for i in range(n - 1):
    s = input().split()
    y = int(s[1]) / int(s[0])
    if y - x > 0.05:
        print("better")
    elif x - y > 0.05:
        print("worse")
    else:
        print("same")
