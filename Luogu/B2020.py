s = list(map(int, input().split()))
ans = int(0)
for i in range(0, 5):
    lst = (i + 4) % 5
    nxt = (i + 1) % 5
    v = s[i] // 3
    ans = ans + s[i] % 3
    s[lst] = s[lst] + v
    s[i] = v
    s[nxt] = s[nxt] + v
print(' '.join(list(map(str, s))))
print(ans)
