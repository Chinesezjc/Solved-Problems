hate = [False, False, False, False, False, False, False, False, False, False]


def check(num):
    for i in num:
        if (hate[int(i)]):
            return False
    return True


string = input()
a = string.split()
n = int(a[0])
k = int(a[1])
string = input()
a = string.split()
for i in range(0, a.__len__()):
    hate[int(a[i])] = True
for i in range(n, n * 100):
    if (check(str(i))):
        print(i)
        exit(0)
