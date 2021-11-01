a, b, c = input().split()
a, b = int(a), int(b)
if c == '+':
    print(a + b)
elif c == '-':
    print(a - b)
elif c == '*':
    print(a * b)
elif c == '/':
    if b==0:
        print("Divided by zero!")
    else:
        print(a // b)
