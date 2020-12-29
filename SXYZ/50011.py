n = int(input())
k = [1]
dp = [[0]]
for i in range(1, n+1):
    k.append(int(input()))
    dp.append([])
    for j in range(0, k[i]):
        numbers = input().split()
        numbers.pop(numbers.__len__() - 1)
        dp[i].append(11451419198101145141919810)
        for l in range(0, numbers.__len__() // 2):
            dp[i][j] = min(dp[i][j], dp[i-1]
                           [int(numbers[l << 1]) - 1] + int(numbers[l << 1 | 1]))
ans = 11451419198101145141919810
for i in range(0, k[n]):
    ans = min(ans, dp[n][i])
print(ans)
