s = input().split()
n = int(s[0])
s.remove(str(n))
a, b, c = s.count('1'),  s.count('5'),  s.count('10')
n = n - s.__len__()
while n != 0:
    s = input().split()
    a, b, c = a + s.count('1'), b + s.count('5'), c + s.count('10')
    n = n - s.__len__()
print(a)
print(b)
print(c)
