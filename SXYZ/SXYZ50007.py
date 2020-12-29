s = input()
num = s.split()
k = int(num[0])+1
s = int(num[1])
ans = 0
for i in range(0, k):
    for j in range(0, k):
        l = s-i-j
        if(0 <= l < k):
            ans += 1
print(ans)
