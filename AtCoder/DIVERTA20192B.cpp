#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct NUM
{
    int P, Q;
} num[5001];
bool cmp(const NUM &A, const NUM &B)
{
    if (A.P == B.P)
    {
        return A.Q < B.Q;
    }
    return A.P < B.P;
}
int n, x[51], y[51], cnt, p, q, now, ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
        for (int j = 1; j < i; ++j)
        {
            ++cnt;
            num[cnt].P = x[i] - x[j];
            num[cnt].Q = y[i] - y[j];
            ++cnt;
            num[cnt].P = x[j] - x[i];
            num[cnt].Q = y[j] - y[i];
        }
    }
    sort(num + 1, num + 1 + cnt, cmp);
    for (int i = 1; i <= cnt; ++i)
    {
        if (q != num[i].Q || p != num[i].P)
        {
            q = num[i].Q;
            p = num[i].P;
            ans = max(now, ans);
            now = 0;
        }
        ++now;
    }
    ans = max(now, ans);
    printf("%d", n - ans);
    return 0;
}
