import math


def isPrime(x: int) -> bool:
    for i in range(2, int(math.sqrt(x))):
        if x % i == 0:
            return False
    return True


mod = 1
for i in range(2, int(math.sqrt(1e9))):
    if isPrime(i):
        mod = mod * (i ** int(math.log(1e9, i)))

print(mod)
