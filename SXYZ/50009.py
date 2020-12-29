def min(A, B):
    return A if(A < B)else B


def abs(A):
    return A if(A > 0)else -A


n = int(input())
for i in range(0, n):
    for j in range(0, n):
        print(format(n//2-min(min(i, j), min(n-i, n-j)-1)+(n % 2), " >5"), end='')
    print()
