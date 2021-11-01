a, b = input().split()
a = int(a) - int(b)
if a < 0:
    print('<')
elif a == 0:
    print('=')
else:
    print('>')
