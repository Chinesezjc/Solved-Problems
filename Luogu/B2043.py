a = int(input())
b = [3, 5, 7]
c = []
for i in b:
    if a % i == 0:
        c.append(i)
if c.__len__() > 0:
    print(' '.join(list(map(str, c))))
else:
    print('n')
